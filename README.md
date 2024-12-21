# Typlyp

# Стек
Плюсы + LLVM
https://miro.com/app/board/uXjVLWIFX0U=/

# Ход работы
- Написана грамматика и примеры кода **(Женя)**
- Подключен ANTLR4 runtime **(Даня Т)**

# Небольшое введение
## Testcases
Женя уже написал целиком три программы, которые мы будем показывать для защиты языка.
Они находятся в `/scratches`. Может будет полезно, чтобы понять какие 
конструкции используются

## Точка входа в программу
Пока что это `main.cpp`, там небольшой скриптик, который читает входной файл
и пропускает его через ANTLR.

## ANTLR4
Лексер, парсер, токенайзер, короче **всё**, что связано с синтаксисом и грамматикой языка
работает с помощью библиотеки ANTLR4

---

Для работы с ней можно загрузить [удобный плагин](https://plugins.jetbrains.com/plugin/7358-antlr-v4)
для ide. Ему можно скормить текст нашего языка (или файлик из `/scratches`) и он его
распарсит. Можно посмотреть как выглядит дерево парсинга и из каких
конструкций состоит язык
### Описание грамматики
В этом фреймворке вся грамматика описывается единственным файлом **typlyp.g4**
Можно его полистать, может быть полезно, чтобы понять, какие бывают выражения,
утверждения и т.п.

Дальше с помощью тулзы (которую можно взять с гх antlr4), либо с помощью плагина для
ide генерируются .h и .cpp файлы для парсинга и составления **parse tree**.

Все файлы связанные с этой частью лежат в `/grammar`

---

### Построение AST
Дальше по идее нужно из этого дерева парсинга построить абстрактное синтаксическое дерево.
<u>Пока что</u> непонятно чем оно критически отличается от дерева парсинга, которое
ANTLR и так умеет строить. Я предполагаю, что AST - просто удобный маппинг этого дерева
на ООП, так чтобы потом было удобно прикручивать LLVM

---
Всё, что связано с AST лежит в `/ast`
- `ASTNode.h` - базовый узел АСТ-дерева
- `/nodes` - реализации остальных узлов дерева
- `ASTBuilder.h` - строитель дерева, наследуется от `/grammar/typlypBaseVisitor.h`. В него
передаем начальный узел (`nodes/ProgramNode.h`) и он строит с него дерево
---
Суть проста, сейчас дерево парсинга состоит из оч непонятных сложных классов, в которых
много лишнего. нужно переложить их в понятные красивые хайповые классы.

Ну и к тому же классы дерева парсинга менее детальны чем планируемое дерево АСТ.
Например, планируется что в АСТ будет отдельная нода для бинарной операции, а в дереве
парсинга такого нет!!

---

### Работа с llvm.

Добавил llvm-project как git submodule, при pull вам скачается llvm сурс файлы(+- 3 гб). Могут быть проблемы с clrf и rf читай предупреждения, которые может кидать гит
Чтобы сбилдить сам llvm нужны cmake(https://community.chocolatey.org/packages/cmake) и ninja(https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages), их нужно установить, удобнее всего через менеджеры пакетов, ссылки чуть раньше. 

Что бы сделать билд нужно прописать
- cmake -S llvm -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug (Release, RelWithDebInfo)
- ninja -C build check-llvm
- Debug - дебаг, долго компилится - дает много дебаг инфы
- Release - быстро компилится - ноль дебаг инфы
- RelWithDebInfo - что-то среднее между Debug и Release
- Подробнее тут https://llvm.org/docs/GettingStarted.html

Теперь в папке build должны появиться нужные файлы для работы кодгена, нужно подключить их через cmake файл

---

## TODO

### AST
- Нужно добавить смысл (пока его нет)
- Поддержка 128 битовых чисел (заиспользовать boost?)
