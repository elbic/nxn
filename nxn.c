//Victor Ortiz 2009
int det(int **A, int n){
    int **B;
    int ai,aj,i,j,bi=0,bj=0,signo;
    if(!( B =(int **)malloc(sizeof(int)*n))){
        printf("***Error: insufiencte espacio de memoria");
        exit(1);
    }
    for(i = 0; i<n; i++)
        if(!( B[i] =(int *)malloc(n*sizeof(int)))){
            printf("***Error: insufiencte espacio de memoria");
            exit(1);
        }
    i = 0;
    int deter = 0;
    for(j = 0; j < n; j++){
        ///CREO LA MATRIZ DE COFACTORES
        bi = 0;
        for(ai = 0; ai < n; ai++){
            bj = 0;
                if(ai != i){
                    for(aj = 0; aj < n; aj++)
                        if(aj != j){
                            B[bi][bj] = A[ai][aj]; //MATRIZ DE COFACTORES
                            bj++;
                        }
                bi++;
                }
         }
        signo = pow(-1.0,(i+j+2));
        if(n == 2)
            deter += (signo*A[i][j]*B[0][0]);
        else
            deter += (signo * A[i][j] * det(B,bj));
    }
    free(B);
    return deter;
}
