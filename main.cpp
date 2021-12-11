#include <iostream>
#include <cstdio>

#define mt double

void read_matrix(FILE *fin, mt **A, size_t &N) {

    fscanf(fin, "%d", &N);
    std::cout << N << "\n";
    *A = new mt[N*N]; mt *B = *A;
	while (fscanf(fin, "%lf", B++) == 1);
}

void print_matrix(size_t n, size_t m, mt *A) {

    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < m; ++j) 
           std::cout << A[i*m+j] << " ";
        std::cout << "\n";
    }
}

int main(int argc, char *argv[]) {

    
    FILE* fin = fopen("in.txt", "r");
    if (fin == NULL) {
        perror ("Ошибка открытия файла");
        return -1;
    }
    
    size_t N;
    mt *A = NULL;
    read_matrix(fin, &A, N);
    print_matrix(N, N, A);

    delete[] A;
    return 0;
}