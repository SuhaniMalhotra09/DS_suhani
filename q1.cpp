#include <stdio.h>

 Q1: Menu driven program for Array operations 
void menuDrivenArray() {
    int arr[100], n = 0, choice, pos, val, i, search, found;

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // CREATE
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;

            case 2: // DISPLAY
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 3: // INSERT
                if (n == 100) {
                    printf("Array is full.\n");
                    break;
                }
                printf("Enter position (0-%d): ", n);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &val);
                for (i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = val;
                n++;
                break;

            case 4: // DELETE
                if (n == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                printf("Enter position (0-%d): ", n - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position.\n");
                    break;
                }
                for (i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                break;

            case 5: // LINEAR SEARCH
                if (n == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                printf("Enter value to search: ");
                scanf("%d", &search);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == search) {
                        printf("Element found at position %d\n", i);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Element not found.\n");
                }
                break;

            case 6: // EXIT
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}
