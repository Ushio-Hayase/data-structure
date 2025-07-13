#include <cmath>
#include <memory>

template <typename T>
class SegmentTree
{
   public:
    SegmentTree(const T* const ptr, size_t size)
        : arr_(new T[1 << (static_cast<int>(ceil(log2(size))) + 1)]), src_(new T[size]), size_(size)
    {
        memcpy(src_, ptr, size * sizeof(T));
        init_segment_tree(ptr, 1, 0, size - 1);
    }

    T find(size_t left, size_t right) { return find_(1, 0, size_ - 1, left, right); }

    void replace(size_t idx, T value)
    {
        replace_(1, 0, size_ - 1, idx, value - src_[idx]);
        src_[idx] = value;
    }

   private:
    T init_segment_tree(const T* const ptr, size_t node, size_t start, size_t end)
    {
        if (start == end) return arr_[node] = arr_[start];
        size_t mid = (start + end) / 2;
        T left = init_segment_tree(arr_, node * 2, start, mid);
        T right = init_segment_tree(arr_, node * 2 + 1, mid + 1, end);
        arr_[node] = left + right;

        return left + right;
    }

    T find_(size_t node, size_t start, size_t end, size_t left, size_t right)
    {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return arr_[node];

        size_t mid = (start + end) / 2;
        T left_res = find_(node * 2, start, mid, left, right);
        T right_res = find_(node * 2 + 1, mid + 1, end, left, right);

        return left_res + right_res;
    }

    void replace_(size_t node, size_t start, size_t end, size_t idx, size_t diff)
    {
        if (idx < start || idx > end) return;
        arr_[node] = arr_[node] + diff;

        if (start != end)
        {
            size_t mid = (start + end) / 2;
            replace_(node * 2, start, end, idx, diff);
            replace_(node * 2 + 1, mid + 1, end, idx, diff);
        }
    }

    T* arr_ = nullptr;
    T* src_ = nullptr;
    size_t size_ = 0;
};