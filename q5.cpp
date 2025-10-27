Q5: Sum of every row and column
void sumRowsColumns() {
    int r, c, i, j;
    printf("Enter rows and columns of matrix: ");
    scanf("%d%d", &r, &c);
    int a[r][c];

    printf("Enter matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    printf("Sum of each row:\n");
    for (i = 0; i < r; i++) {
        int sum = 0;
        for (j = 0; j < c; j++)
            sum += a[i][j];
        printf("Row %d = %d\n", i + 1, sum);
    }

    printf("Sum of each column:\n");
    for (j = 0; j < c; j++) {
        int sum = 0;
        for (i = 0; i < r; i++)
            sum += a[i][j];
        printf("Column %d = %d\n", j + 1, sum);
    }
}
