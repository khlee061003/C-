#include <stdio.h>

#define PRODUCT_COUNT 5

int stock[PRODUCT_COUNT] = { 0 };
int sold[PRODUCT_COUNT] = { 0 };

// ������ �Է� ó�� �Լ�
int safeScanInt(const char* msg, int* var) {
    printf("%s", msg);
    if (scanf_s("%d", var) != 1) {
        printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
        while (getchar() != '\n'); // ���� ����
        return 0; // ����
    }
    return 1; // ����
}

// �޴� ��� �Լ�
void printMenu() {
    printf("\n[���θ� ���� ���α׷�]\n");
    printf("���ϴ� �޴��� �����ϼ���.\n");
    printf("1. �԰�\n");
    printf("2. �Ǹ�\n");
    printf("3. ��ǰ��Ȳ\n");
    printf("4. ����\n");
    printf(">> ");
}

// �԰� �Լ�
void inputStock() {
    int choice;
    if (!safeScanInt("\n(���)�԰���� �Է� : ��ü ��ǰ �Է� 1, ���� ��ǰ �Է� 2�� ����\n>> ", &choice))
        return;

    if (choice == 1) {
        int qty;
        if (!safeScanInt("(�Է�) ��ü ��ǰ �԰���� �Է� : ", &qty))
            return;
        for (int i = 0; i < PRODUCT_COUNT; i++) {
            stock[i] += qty;
        }
    }
    else if (choice == 2) {
        int id, qty;
        if (!safeScanInt("��ǰ ID (0~4) �Է� : ", &id))
            return;
        if (id >= 0 && id < PRODUCT_COUNT) {
            if (!safeScanInt("�԰���� �Է� : ", &qty))
                return;
            stock[id] += qty;
        }
        else {
            printf("�߸��� ��ǰ ID�Դϴ�.\n");
        }
    }
    else {
        printf("�߸��� �����Դϴ�.\n");
    }
}

// �Ǹ� �Լ�
void sellProduct() {
    int choice;
    if (!safeScanInt("\n(���)�Ǹż��� �Է� : ��ü ��ǰ �Է� 1, ���� ��ǰ �Է� 2�� ����\n>> ", &choice))
        return;

    if (choice == 1) {
        int qty;
        if (!safeScanInt("��ü ��ǰ �Ǹż��� �Է� : ", &qty))
            return;
        for (int i = 0; i < PRODUCT_COUNT; i++) {
            if (stock[i] >= qty) {
                stock[i] -= qty;
                sold[i] += qty;
            }
            else {
                printf("��ǰ %d: ��� �������� �Ǹ� �Ұ�\n", i);
            }
        }
    }
    else if (choice == 2) {
        int id, qty;
        if (!safeScanInt("��ǰ ID (0~4) �Է� : ", &id))
            return;
        if (id >= 0 && id < PRODUCT_COUNT) {
            if (!safeScanInt("�Ǹż��� �Է� : ", &qty))
                return;
            if (stock[id] >= qty) {
                stock[id] -= qty;
                sold[id] += qty;
            }
            else {
                printf("��� �������� �Ǹ� �Ұ�\n");
            }
        }
        else {
            printf("�߸��� ��ǰ ID�Դϴ�.\n");
        }
    }
    else {
        printf("�߸��� �����Դϴ�.\n");
    }
}

// ��ǰ ��Ȳ ���
void showStatus() {
    printf("\n[��ǰ ��Ȳ]\n");
    printf("��ǰID\t������\t�Ǹż���\n");
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("%d\t%d\t\t%d\n", i, stock[i], sold[i]);
    }
}

// ���� �Լ�
int main() {
    int menu;

    while (1) {
        printMenu();
        if (!safeScanInt("", &menu))
            continue;

        switch (menu) {
        case 1:
            inputStock();
            break;
        case 2:
            sellProduct();
            break;
        case 3:
            showStatus();
            break;
        case 4:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �޴� �����Դϴ�.\n");
        }
    }

    return 0;
}