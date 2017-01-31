//int_sorted.cpp
#include "int_sorted.h"

int_sorted::int_sorted() {
    buffer = new int_buffer(0);
}

int_sorted::int_sorted(const int* source, size_t size) {
    this->buffer = new int_buffer(source, size);

}

size_t int_sorted::size() const {
    return (*buffer).size();
}

bool int_sorted::checksorted() {
    size_t tempsize = (*buffer).size();
    for (int* i = (*buffer).begin(); i < ((*buffer).begin() + tempsize - 1); i++) {
        if (*i > *(i + 1)) {
            return false;
        }
    }
    return true;
}

int* int_sorted::insert(int value) {
    int* pointer = buffer->end();
    *pointer = value;
    pointer = buffer->begin();
    buffer = new int_buffer(pointer, (buffer->size() + 1));
    return buffer->end();
}

const int* int_sorted::begin() const {
    return (*buffer).begin();
}

const int* int_sorted::end() const {
    return (*buffer).end();
}

int_sorted int_sorted::selectionSort() {
    using namespace std;
    clock_t t1 = clock();
    int_sorted tempsort(buffer->begin(), size());
    if (!checksorted()) {
        int* front = tempsort.buffer->begin();
        int* ending = tempsort.buffer->end();
        int* iter = front;
        int* min = front;
        while (front != ending) {
            min = front;
            iter = front;
            iter++;
            while (iter != ending) {
                if (*min > *iter) {
                    min = iter;
                }
                iter++;
            }
            if (min != front && *min < *front) {
                std::swap(*min, *front);
            }
            front++;
        }
    }
    clock_t t2 = clock();
    double elapsed = double(t2 - t1) / CLOCKS_PER_SEC;
    cout << "Time to sort with custom selection-sort: " << elapsed << " secs" << endl;
    return tempsort;
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const {
    int* i = (*buffer).begin();
    int* j = merge_with.buffer->begin();
    int_sorted newsorted;
    while (i != (*buffer).end() && j != merge_with.buffer->end()) {
        if (*i > *j) {
            newsorted.insert(*j);
            j++;
        } else {
            newsorted.insert(*i);
            i++;
        }
    }
    while (i != (*buffer).end()) {
        newsorted.insert(*i);
        i++;
    }
    while (j != merge_with.buffer->end()) {
        newsorted.insert(*j);
        j++;
    }
    return newsorted;
}
