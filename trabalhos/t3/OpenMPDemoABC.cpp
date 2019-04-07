#include <algorithm>
#include <iostream>
#include <string>
#include <omp.h>

class SharedArray {
private:
    char* array;
    int index;
    int size;
public:
    SharedArray(int n) : size(n), index(0) {
        array = new char[size];
        std::fill(array, array + size, '-');
    }

    ~SharedArray() {
        delete[] array;
    }

    void addCharCritical(char c) {
#pragma omp critical
        {
            array[index] = c;
            spendSomeTime();
            index++;
        }
    }

    void addCharSemCritical(char c){
        array[index] = c;
        spendSomeTime();
        index++;
    }

    int countOccurrences(char c) {
        return std::count(array, array + size, c);
    }

    std::string toString() {
        return std::string(array, size);
    }

private:
    void spendSomeTime() {
        for (int i = 0; i < 10000; i++) {
            for (int j = 0; j < 100; j++) {
                // These loops shouldn't be removed by the compiler
            }
        }
    }
};

class ArrayFiller {
private:
    SharedArray* array;
    static const int nThreads = 3;
    static const int nTimes = 60;
    int schedule;
    int chunkSize = 10;
    bool useChunk;

public:
    ArrayFiller(int sched, bool usechunk) {
        array = new SharedArray(nTimes);
        schedule = sched;
        useChunk = usechunk;
    }

    ~ArrayFiller() {
        delete array;
    }

    void fillArray() {
        int i;
        if(!useChunk) chunkSize = 1;

        omp_set_num_threads(3);
        switch (schedule) {
            case 1:
#pragma omp parallel for schedule(static, chunkSize) private(i)
                for (i = 0; i < nTimes; i++) {
                    array->addCharCritical('A' + omp_get_thread_num());
                }
                break;
            case 2:
#pragma omp parallel for schedule(dynamic, chunkSize) private(i)
                for (i = 0; i < nTimes; i++) {
                    array->addCharCritical('A' + omp_get_thread_num());
                }
                break;
            case 3:
#pragma omp parallel for schedule(guided, chunkSize) private(i)
                for (i = 0; i < nTimes; i++){
                    array->addCharCritical('A' + omp_get_thread_num());
                }
                break;
            case 4:
#pragma omp parallel for schedule(runtime) private(i)
                for (i = 0; i < nTimes; i++) {
                    array->addCharCritical('A' + omp_get_thread_num());
                }
                break;
            case 5:
#pragma omp parallel for schedule(auto) private(i)
                for (i = 0; i < nTimes; i++) {
                    array->addCharCritical('A' + omp_get_thread_num());
                }
                break;
            case 6:
#pragma omp parallel for schedule(auto) private(i)
                for (i = 0; i < nTimes; i++) {
                    array->addCharSemCritical('A' + omp_get_thread_num());
                }
                break;
            case 7:
#pragma omp parallel for private(i)
                for (i = 0; i < nTimes; i++) {
                    array->addCharSemCritical('A' + omp_get_thread_num());
                }
                break;
        }
    }

    void printStats() {
        std::cout << array->toString() << std::endl;
        for (int i = 0; i < nThreads; ++i)
            std::cout << (char) ('A' + i) << "=" << array->countOccurrences('A' + i) << std::endl;
    }
};

int main() {
    std::cout << "Case 1: Schedule static, com especificacao do chunk" << std::endl;
    ArrayFiller m1(1, true);
    m1.fillArray();
    m1.printStats();

    std::cout << "Case 2: Schedule static, sem especificacao do chunk" << std::endl;
    ArrayFiller m2(1, false);
    m2.fillArray();
    m2.printStats();
   
    std::cout << "Case 3: Schedule dynamic, com especificacao do chunk" << std::endl;
    ArrayFiller m3(2, true);
    m3.fillArray();
    m3.printStats();

    std::cout << "Case 4: Schedule dynamic, sem especificacao do chunk" << std::endl;
    ArrayFiller m4(2, false);
    m4.fillArray();
    m4.printStats();

    std::cout << "Case 5: Schedule guided, com especificacao do chunk" << std::endl;
    ArrayFiller m5(3, true);
    m5.fillArray();
    m5.printStats();

    std::cout << "Case 6: Schedule guided, sem especificacao do chunk" << std::endl;
    ArrayFiller m6(3, false);
    m6.fillArray();
    m6.printStats();

    std::cout << "Case 7: Schedule runtime" << std::endl;
    ArrayFiller m7(4, true);
    m7.fillArray();
    m7.printStats();

    std::cout << "Case 8: Schedule auto" << std::endl;
    ArrayFiller m8(5, true);
    m8.fillArray();
    m8.printStats();

    std::cout << "Case 9: Sem exclusao mutua, mas com schedule auto" << std::endl;
    ArrayFiller m9(6, true);
    m9.fillArray();
    m9.printStats();

    std::cout << "Case 9: Sem exclusao mutua e sem schedule definido" << std::endl;
    ArrayFiller m10(7, true);
    m10.fillArray();
    m10.printStats();
}
