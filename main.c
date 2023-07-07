#include <stdio.h>
#include <math.h>

int countIntersectionPoints(int x1, int y1, int r1, int x2, int y2, int r2) {
    double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    if (distance > r1 + r2) {
        return 0; // Кола не перетинаються
    } else if (distance == r1 + r2) {
        return 1; // Кола торкаються ззовні
    } else if (distance < fabs(r1 - r2)) {
        return 0; // Одне коло міститься всередині іншого
    } else if (distance == 0 && r1 == r2) {
        return -1; // Кола співпадають
    } else if (distance == 0 && r1 != r2) {
        return 0; // Кола розміщені одне в одному, але не перетинаються
    } else {
        return 2; // Кола перетинаються в двох точках
    }
}

int main() {
    int x1, y1, r1, x2, y2, r2;
    printf("Введіть координати центру першого кола (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Введіть радіус першого кола (r1): ");
    scanf("%d", &r1);
    printf("Введіть координати центру другого кола (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Введіть радіус другого кола (r2): ");
    scanf("%d", &r2);

    int result = countIntersectionPoints(x1, y1, r1, x2, y2, r2);
    printf("Кількість точок перетину: %d\n", result);

    return 0;
}
