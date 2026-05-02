# Laboratory work V

Данная лабораторная работа посвящена изучению фреймворков для тестирования на примере **GTest**.

## Задание

В ходе выполнения лабораторной работы был подготовлен проект `lab05` на основе предыдущей лабораторной работы `lab04`.

В проект был добавлен фреймворк GoogleTest в виде git submodule:

```bash
git submodule add https://github.com/google/googletest third-party/gtest
````

После этого была подключена сборка тестов через CMake и создан тестовый файл `tests/test1.cpp`.

## Сборка проекта

Для сборки проекта с тестами используется команда:

```bash
cmake -H. -B_build -DBUILD_TESTS=ON -DCMAKE_CXX_FLAGS="-Wno-error=maybe-uninitialized"
cmake --build _build
```

## Запуск тестов

Запуск тестов выполняется командой:

```bash
cmake --build _build --target test
```

Также можно запустить тестовый исполняемый файл напрямую:

```bash
_build/check
```

## Результат

В результате выполнения теста проверяется функция `print`, которая записывает строку в файловый поток.

Ожидаемый результат:

```text
[  PASSED  ] 1 test.
```

## Автор

**GitHub:** eroshinpetr
**Email:** [eroshinpetr1@gmail.com](mailto:eroshinpetr1@gmail.com)
