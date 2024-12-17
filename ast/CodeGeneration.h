#include "llvm/DerivedTypes.h"
#include "llvm/LLVMContext.h"
#include "llvm/Module.h"
#include "llvm/Support/IRBuilder.h"

// Value *ErrorV(const char *Str) { Error(Str); return 0; } // Обработчик ошибок (у нас вообще он будет???)
static LLVMContext context;
static Module *TheModule; //LLVM-конструкция, содержит все функции/глобалы в куске кода
static IRBuilder<> Builder(context); //вспомогательный объект, помогает генерировать инструкции LLVM
static std::map<std::string, Value*> NamedValues; //таблица символов

