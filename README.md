# Проект "Push Swap"
![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Mac OS](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0)
![IntelliJ IDEA](https://img.shields.io/badge/IntelliJIDEA-000000.svg?style=for-the-badge&logo=intellij-idea&logoColor=white)

### Описание проекта
Привет, мир :metal:

Задача этого проекта - написать наиболее оптимальный алгоритм, который должен отсортировать по возрастанию [стек](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) случайных целых чисел "А" с использованием ограниченного набора инструкций.
При этом, разрешено использовать вспомогательный пустой стек "B".
Таким образом, алгоритм в своей работе должен использовать минимально возможное количество действий.

### Доступные инструкции
| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

### Демонстрация работы алгоритма
![project demonstration](./push_swap_demo.gif)

### Использование
Запуск:
```bash
git clone https://github.com/Dronoti/push_swap.git push_swap && cd push_swap && cd src && make && make clean && ./push_swap 3 1 2 -1 5
```
С помощью аргументов командной строки программа принимает на вход набор случайных целых чисел и выводит список инструкций, которые требуются для сортировки стека.

### Дополнительно
Подробная функциональность программы, ограничения и требования к ее реализации описаны в [задании.](./push_swap.pdf)