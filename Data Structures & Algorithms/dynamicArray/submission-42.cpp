class DynamicArray {
public:

    int *arr;
    int length = 0;
    int array_capacity = 0;

    DynamicArray(int capacity) {
       arr = new int[capacity]; 
       array_capacity = capacity;
    }

     ~DynamicArray() {
        delete[] arr;
    }

    int get(int i) {
        if (i < 0 || i >= length) {
            // Handle out-of-bounds access (e.g., throw exception)
            std::cerr << "Error: Index out of bounds!" << std::endl;
            return -1; // Or throw an exception
        }
        return arr[i];
    }

    void set(int i, int n) {
        if(i < length){
            arr[i] = n;
        }
    }

    void pushback(int n) {
        if(length == array_capacity){
            resize();
        }
        arr[length++] = n;
    }

    int popback() {
        if(length > 0){
           return arr[--length];
        } else {
            // Handle out-of-bounds access (e.g., throw exception)
            std::cerr << "Error: Index out of bounds!" << std::endl;
            return -1; // Or throw an exception
        }
    }

    void resize() {
        array_capacity = array_capacity * 2;
        int* newArr = new int[array_capacity];
        for(int i = 0; i < length; i++){
            newArr[i] = arr[i];
        }
        arr = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return array_capacity;
    }
};
