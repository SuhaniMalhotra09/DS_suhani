Q4(c) Transpose of a Matrix 
void transposeMatrix() {
    int r, c, i, j;
    printf("Enter rows and columns of matrix: ");
    scanf("%d%d", &r, &c);
    int a[r][c], t[c][r];

    printf("Enter matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            t[j][i] = a[i][j];

    printf("Transpose:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }
}
