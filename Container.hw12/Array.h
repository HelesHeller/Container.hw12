#include <iostream>

using namespace std;

template<typename T>
class Array {

private:

    T* array;
    int size;
    int capacity;
    int grow;

public:

    Array(int size = 0, int capacity = 10, int grow = 1)
        : array(new T[capacity]), size(0), capacity(capacity), grow(grow) {

        if (size > 0)
            SetSize(size);
    }

    ~Array() {

        if (array != nullptr)
            delete[] array;
    }

    Array(const Array&) = delete;

    Array& operator=(const Array& object) {

        delete[] array;

        size = object.size;
        capacity = object.capacity;
        grow = object.grow;

        array = new T[capacity];

        for (int i = 0; i < size; i++)
            array[i] = object.array[i];

        return *this;
    }

    T& operator[](int index) const {

        return array[index];
    }

    void SetSize(int size, int grow = 1) {

        if (size > capacity) {

            capacity = size + (grow - size % grow);

            T* temp = new T[this->capacity];

            for (int i = 0; i < size; i++)
                temp[i] = array[i];

            delete[] array;
            array = temp;
        }

        this->size = size;
        this->grow = grow;
    }

    void SetAt(int index, const T& value) {

        if (index >= 0 && index < size)
            array[index] = value;
    }

    int GetSize() const {

        return size;
    }

    int GetCapacity() const {

        return capacity;
    }

    int GetUpperBound() const {

        return size - 1;
    }

    T& GetAt(int index) const {

        return array[index];
    }

    T* GetData() const {

        return array;
    }

    bool IsEmpty() const {

        return size == 0;
    }

    void FreeExtra() {

        if (size < capacity) {

            capacity = size;

            T* temp = new T[capacity];

            for (int i = 0; i < size; i++)
                temp[i] = array[i];

            delete[] array;
            array = temp;
        }
    }

    void RemoveAll() {

        delete[] array;

        array = nullptr;
        size = 0;
        capacity = 0;
    }

    void Add(const T& value) {

        if (size == capacity) {

            int recapacity = capacity + grow;

            T* temp = new T[recapacity];

            for (int i = 0; i < size; i++)
                temp[i] = array[i];

            delete[] array;
            array = temp;
            capacity = recapacity;
        }

        array[size] = value;
        size++;
    }


    void Append(const Array& object) {

        int resize = size + object.size;

        if (resize > capacity) {

            capacity = resize + (grow - resize % grow);

            T* temp = new T[capacity];

            for (int i = 0; i < size; i++)
                temp[i] = array[i];

            delete[] array;
            array = temp;
        }

        for (int i = 0; i < object.size; i++) {

            array[size] = object.array[i];
            size++;
        }
    }

    void InsertAt(int index, const T& value) {

        if (index >= 0 && index <= size) {

            if (size == capacity)
                SetSize(size + grow);

            for (int i = size; i > index; i--)
                array[i] = array[i - 1];

            array[index] = value;
            size++;
        }
    }

    void RemoveAt(int index) {

        if (index >= 0 && index < size) {

            for (int i = index; i < size - 1; i++)
                array[i] = array[i + 1];

            size--;

            if (size < capacity - grow) {

                int recapacity = capacity - (capacity % grow);

                if (recapacity < size)
                    recapacity += grow;

                T* temp = new T[recapacity];

                for (int i = 0; i < size; i++)
                    temp[i] = array[i];

                delete[] array;
                array = temp;
                capacity = recapacity;
            }
        }
    }
};