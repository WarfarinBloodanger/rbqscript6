# 值与变量

## 值

RBQScript 是一门动态类型的语言，变量无类型，值才有类型。不会限制所保存的值类型。

在 RBQScript 中，内置了以下几种**原生数据类型**：

- 浮点数（number）：不低于 IEEE 标准下 double 精度的带符号实数；
- 字符串（string）：若干单字节字符组成的序列；
- 函数（function）：可执行的指令流；
- 引用（reference）：指向复合数据结构的指针的统称。内置了以下两子类：
- - 数组（array）：线性表数据结构；
- - 对象（object）：包含属性信息的复合数据结构；
- 真 / 假（true / false）：表示真 / 假的布尔型值；
- 未定义（undefined）：代表未初始化的内存（如：未声明的变量、未赋初值的数组 / 对象元素等）；
- 空值（null）：表示空，不同于 undefined。

### 浮点数

浮点数可以保存小数，支持以下多种格式：

- 普通数字写法，如 `0.123`；
- 科学计数法，如 `1.5e5`；
- 十六进制写法，如 `0xcff0`；
- 特别地，如果是用十六进制写法或普通数字写法的**整数**，允许在数字内部带上下划线，以作分位符之用，如下：

```
1_000_000
0xccff_ddaa
```

下划线不会影响数字的值。

### 字符串

RBQScript 使用 ASCII 字符保存字符串，字符串需要使用双引号 `""` 或者单引号 `''` 括起来，**字符串内部不允许有换行符**。如下：

```
"hello"
'this is a text'
```

请注意，包含非 ASCII 字符的字符串可能无法跨平台直接运行，比如 `"汉字"` 等包含中文的字符串，可能因为平台编码的不相同而导致乱码。

如果要在字符串内部加上一些特殊字符，需要用反斜杠 `\` 转义。RBQScript 的字符串支持以下几种转义字符：

```
\\ \r \n \t \b \a \' \"
```

此外，RBQScript 还额外提供了一个 `\u` 转义字符，它用于编码 UTF-8 字符序列，其语法为 `\u` 后面跟上四个十六进制字符，比如：

```
Console.print('\u4f60\u597d')
```

运行这串代码，如果您的控制台字符编码为 UTF-8，那么将会输出“你好”。如何改变控制台编码以达到预期效果，请自行查阅相关文档。

### 函数

函数是一种包含着一些列指令的特殊数据类型。在 RBQScript 里，函数可以赋值给变量；而调用函数的方式为 `func(arg1,arg2,...)`，比如：

```
test()
len('hello')
Math.pow(2,10)
```

具体如何定义自定义函数以及函数的相关行为的具体描述将在下面对应小节描述。

### 数组

在 RBQScript 里，数组是用中括号 `[]` 括起来的一组用逗号隔开的元素。数组内的元素类型可以不同，甚至可以是嵌套数组，比如：

```
[1,2,3]
[1,'hello']
[[1,2],[3,4]]
```

使用方括号来访问数组元素，格式为 `[index]`。如下：

```
a[0]
b[5]
[1,2,3,4][1]
```

RBQScript 的数组下标**从 0 开始**。因此上面的代码访问的依次是 `a` 的第一个元素、`b` 的第六个元素和数组 `[1,2,3,4]` 的第二个元素（也就是 2）。

访问不存在的下标将会返回 undefined。

### 对象

对象可以理解成具有键值对的一组映射关系的集合。对象的格式为用逗号分隔开的一系列 `key:value` 形式的键值对，如下：

```
{
  key1:value1,
  key2:value2,
  ...
}
```

在这里，`key:value` 的键值 `key` 可以**不加引号**，比如下面是一些对象的例子，其中前两个对象所包含的内容是完全相同的：

```
{'a':'A','b':'B'}
{a:'A',b:'B'}
{'ver':2,'dict:{'world':'sekai'}}
```

访问对象的元素可以使用 `[index]` 形式或者 `.index` 形式。如下：

```
{'a':'A'}['a']
obj.index.index2
{'ver':2,'dict:{'world':'sekai'}}['dict'].world
```

访问不存在的键值将会返回 undefined。


### 引用

如上，数组和对象都属于引用，因此变量直接赋值的时候，只是把**引用**赋值给了新的变量，如下：

```
a=[1,2,3]
b=a
b[0]='test'
Console.print(a[0])
```

这段代码将会输出 `test` 字符串。原因在于：变量 `b` 经过直接赋值之后，指向的是和 `a` 同样的一个数组，因此对 `b` 的修改就会导致 `a` 也跟着改变。

同样的，对象也是引用：

```
obj={'a':0}
obj2=obj
obj2.a=10
Console.print(obj.a)
```

这段代码将会输出 `10`。原因在于：原因在于：变量 `obj2` 经过直接赋值之后，指向的是和 `obj` 同样的一个对象，因此对 `obj2` 的修改就会导致 `obj` 也跟着改变。

### 真 / 假

RBQScript 里提供了 `true` 和 `false` 两个关键字来指代真和假两个布尔值。

需要注意的是，RBQScript 里的逻辑运算符不一定返回布尔值。具体请参阅下面的对应小节。

## 变量

### 命名

RBQScript 支持变量。变量拥有一个标识符。标识符必须以**字母、数字或下划线**组成，并且开头必须是**字母或下划线**。比如如下代码：

```
a=1
version_2_info='beta'
__name__='test_module'
```
上面这份代码出现了三个变量：`a`、`version_2_info` 和 `__name__`。

RBQScript 建议使用下划线式命名法。

### 内置变量

为了给用户提供更加方便的编程体验，RBQScript 提供了一些内置函数 / 变量，比如数学库的 `Math` 变量、控制台操作的 `Console` 变量以及原生函数 `len` 等，详情可以查看下文内置函数一章。

### 变量作用域

RBQScript 中，默认所有**非函数参数**（见下）的变量都是全局的。如下：

```
a=1
{
  a=2
}
```

其中，用大括号括起来的若干条语句称为**块语句**，它能够帮助划分代码模块。执行这段代码之后，全局变量 `a` 的值将会变成 2。

有时候不希望出现“变量作用域污染”（即：内部作用域修改了外部作用域的变量），此时可以使用 `var` 关键字将其声明成**局部变量**。局部变量有如下行为：

- 局部变量的作用域**只在当前大括号括起来的语句块内部**。
- 当局部变量与外层的变量同名时，**新的局部变量将把外部的变量遮蔽**。外部的变量仍然存在，只是在当前语句块内无法访问到；
- 如果局部变量声明了但是没有被初始化，它的值将变成 null。

语法如下：

```
a=1
b=2
{
  var a=3,b=4
  var c
}
```

执行这段代码之后，`a` 和 `b` 的值在大括号里分别是 3 和 4；但是退出大括号之后，`a` 和 `b` 的值分别会变回 `1` 和 `2`。由于局部变量 `c` 没有被初始化，它的值是 null。

请注意，局部变量只在声明完成之后起作用，也就是说，下面的代码是合法的：

```
a=1
{
  var a=a+1
}
```

在这段代码里，局部变量 `a` 会被初始化成**外围的变量** `a` 加上 1，也就是 2。

# 基本语法

## 运算符

RBQScript 支持一系列运算符。

- **数学运算符**，可执行数学运算：
- - `+ - * / %` 分别对应加、减、乘、除、取模运算（实数取模）。
- **位运算符**，可对数字的进行按位操作，**操作将会舍弃操作数的小数部分**：
- - `<< >>` 分别对应左移，右移运算符，将空余位用 0 填充。
- - `& | ~ ^` 分别对应按位与、按位或、按位取非（单元运算符）和按位异或。
- **逻辑运算符**，可进行逻辑运算：
- - `&& || !` 分别对应逻辑与、逻辑或和逻辑非（单元运算符），**除了 0、null 和 undefined 之外的值都将被视作 true**。
- - `or` 属于**类型或**运算符，将会把**除了 null 和 undefined 之外的值都将被视作 true**
- **比较运算符**，可进行比较运算。
- - `> < >= <= != ==` 分别对应严格大于、严格小于、大于等于、小于等于、不等于和严格等于。
- **取址运算符**，能够提取偏移量所对应的信息：
- - `.` 取成员，语法为 `object.property`；
- - `[]` 取下标，语法为 `object[index]`。`index` 可以是数字或者是字符串，当是字符串时，`object.index` 等价于 `object["index"]`；
- - `()` 函数调用，语法为 `func(arg1,arg2,...)`。
- **赋值运算符**，这些运算符可以修改左值指向的地址 / 变量：
- - `=` 赋值，直接将右边的值赋给左值指向的地址 / 变量；
- - 此外包括 `+=`、`-=` 等带操作的赋值运算符。例如：`left+=value` 的功能相当于 `left=left+value`。
- - 支持带操作的赋值运算符有：`+= -= *= /= %= <<= >>= &= |= ^=`。
- **功能运算符**，这些运算符拥有特定的功能：
- - `typeof` 取类型，语法为 `typeof value`，将会用字符串形式返回 `value` 的类型信息。
- - `has` 判断存在，语法为 `object has key`，判断 `object` 中是否包含 `key` 这个键值，以 `true` 或 `false` 返回结果。
- - `new` 构造对象，语法为 `new Class(field1=value1,field2=value2...)`。具体行为将在本文档的对应小节表述。
- - `is` 判断是否是某种类型，语法为 `val is type`，判断 `val` 是否是 `type` 类型，以 `true` 或 `false` 返回结果。
 
部分语言特性：

- `&& ||` 逻辑运算符是短路运算符。`&&` 返回的是两个运算数中为 `false` 的那一个（两个都为 `false` 返回第一个），`||` 返回的是两个运算符中为 `true` 的那一个（两个都为 `true` 返回第一个）；
- `or` **不进行短路运算**。它与 `||` 的区别在于：0 对于 `or` 来说是真值。`0 or 3` 将会返回 0，而 `0 || 3` 将会返回 3。
- 位运算符将会把实数转化为 64 位长整型进行计算，比如 `3.5 & 1` 实际将会被转化为 `3 & 1`。
- `is` 运算符涉及到对象系统，具体行为在下面对应章节描述。

## 控制流

### if 语句

if 语句根据条件选择要执行的代码分支。格式如下：

```
if(condition)
  true branch
else
  false branch
```

当 condition 为 true（或可以转化为 true 的值）时，将会跳转到 true branch 执行；否则将执行 false branch。

当任意一个 branch 具有多条语句的时候，需要使用大括号将多条语句括起来。

```
if(condition){
  true block
}
else{
  false block
}
```

RBQScript 支持 if-else-if 结构，即以下代码是合法的：

```
if(condition1) branch1
else if(condition2) branch2
else ...
```

在 RBQScript 中，if 将匹配最近的 else，不存在空悬 else 问题。如下代码：

```
if(condition1)
  if(condition2) branch2
else branch3
```

其本质上是：

```
if(condition1) {
  if(condition2) branch2
else branch3
}
```

例如如下代码：

```
if(5+3>9) Console.print('A')
else if(5+3>8) Console.print('B')
else Console.print('C')
```

这段代码将会输出 `C`。

我们建议显式使用大括号来明确各分支的范围，避免出现 else 从句从属关系不明朗而导致的代码理解上的问题。

### while 语句

while 语句会进行循环，其格式如下：

```
while(condition) loop_body
```

这段代码将会不断循环执行 loop_body 中的内容，一直到 condition 不为 true（或者其他可以转化为 true 的值）。如果 loop_body 中包含超过一条语句，那么请使用大括号将其括起来。

例如如下代码：

```
i=0
while(i<3){
  Console.print('i =',i)
  i+=1
}
```

这段代码将会输出：

```
0
1
2
```

### for 语句

for 语句也提供了循环功能，其格式如下：

```
for(statement1; condition; statement2) loop_body
```

这段代码将会首先执行 statement1，然后不断循环执行 loop_body，每执行一次 loop_body 就执行一次 statement2，一直到 condition 不为 true（或者其他可以转化为 true 的值）。如果 loop_body 中包含超过一条语句，那么请使用大括号将其括起来。

严格地讲，以上代码和下面的 while 循环是等价的：

```
statement1
while(condition) {
  loop_body
  statement2
}
```

例如如下代码：

```
for(i=0;i<3;i+=1) Console.print(i)
```

这段代码将会输出：

```
0
1
2
```

### break 语句

break 语句提供了从循环体内部直接跳出循环体的功能，它只应当出现在一个循环当中。

```
for(i=0;i<10;i+=2){
  Console.print(i)
  if(i==6) break
}
Console.print('Out of loop')
```

这段代码将会输出：

```
0
2
4
6
Out of loop
```

当变量 `i` 的值等于 6 时，执行到 break 语句，退出了循环。

### continue 语句

continue 语句提供了从循环体内部直接执行下一轮循环的功能，它只应当出现在一个循环当中。

```
for(i=0;i<10;i+=2){
  if(i==6) continue
  Console.print(i)
}
```

这段代码将会输出：

```
0
2
4
8
```

当变量 `i` 的值等于 6 时，执行到 continue 语句，此时不执行接下来的输出语句。

请注意区分 break 和 continue 的功能差异。break 语句是直接**跳出循环体**，而 continue 语句是**跳过当前当次循环内剩余的所有语句，并开始新一轮循环**。

## 函数

### 函数定义

RBQScript 提供了函数定义的语法，其格式如下：

```
function function_name(arg1,arg2,...){
  block
}
```

例如：

```
function my_func(a,b){

}
```

这段代码将会定义一个函数 `my_func`，它拥有 2 个参数，分别为 `a` 和 `b`。

### 函数参数

有些时候需要检查传递给函数的参数是否是需要的类型，使用 `is` 运算符可以完成这个工作，但是语法稍显冗长。RBQScript 提供**参数类型声明**语法：

```
function name(arg1:type1, arg2:type2,...){}
```

对于所有加了声明的参数，当函数被调用，系统将对每个声明了类型的参数执行 `arg is type`，如果返回值是 false，则报告错误信息。

对于不声明参数的类型，将不检查类型是否符合。

请注意，**函数参数默认为局部变量。** 如下代码：

```
a=1
function test(a){ Console.print(a) }
test(3)
```

这段代码将输出 3。在 `test` 内部的变量 `a` 指向的是函数参数。

### 函数返回值

函数可以拥有返回值，使用 `return` 语句返回值，当函数执行到 return 语句时将会直接中断流程退出。其格式如下：

```
return value
```

其中，返回值 `value` 是可选的。如果没有返回值，那么**必须在 return 后面带上一个分号**，即 `return;`。
- 函数如果通过带返回值的 `return value` 语句返回，则返回值为 `value`；
- 函数如果通过不带返回值的 `return;` 语句返回，则返回值为 null；
- **没有通过 return 退出的函数返回 undefined**。

例如：

```
function test(a:number){
  if(a<0)return;
  if(a>0)return a+9
}
Console.print(test(-1),test(0),test(1))
```

这段代码将会输出：

```
null undefined 10
```

参数为 -1 时函数通过不带返回值的 `return` 语句返回，返回值为 null；参数为 0 时函数自然结束，返回值为 undefined；参数为 1 时函数通过 `return a*a` 语句返回，返回值即为 10。


### 匿名函数

当您有时候需要一个函数但是只需要用到一次时，您可以使用匿名函数来更简单地完成这项工作。其语法如下：

```
function(arg1,arg2,...){block}
```

事实上，下面两段代码是等价的：

```
function f(){}
f=function(){}
```

例如：

```
a=function(x){return x*x}
Console.print(a(5))
```

将会输出 `25`。

### 高阶函数

RBQScript 支持将函数作为返回值返回，并且支持 upvalue 机制（即闭包），如下：

```
function line(k,b){
  return function(x){return k*x+b}
}
Console.print(line(2,3)(1))
Console.print(line(-1,1.5)(0.8))
```

这段代码将会输出：

```
5
0.7
```

可以看到，返回的函数在 upvalue 机制下**互不干扰**。

RBQScript 也支持将函数作为参数传给另一个函数，如下：

```
function hello(v){
  v('Hello')
}
hello(function(x){ Console.print(x) })
```

这段代码将会输出：

```
Hello
```

一个匿名函数被当做参数传给了 `hello` 函数。`hello` 函数将会尝试用参数 `'Hello'` 调用它所得到的参数，于是该匿名函数被执行，输出字符串。


## 类与对象

### 类定义

为了支持 OOP（面向对象编程），RBQScript 提供类的概念。类的定义如下：

```
class name {
  var field1
  var field2,field3
  ...
  constructor(x){}
  constructor(x,y){}
  ...
  function method1(){}
  function method2(){}
  ...
  operator+(rhs){}
  ...
}
```

RBQScript 的类定义包含以下元素：
- `var` 开头的行表示对象的字段，可以用逗号分隔。
- `constructor` 是构造函数，具体将在下面的章节讲述。
- `function` 表示对象的方法；
- `operator` 是运算符重载，具体将在下面的章节讲述。
### 类继承

当需要从一个基类派生出多个子类的时候，可以采用如下语法：

```
class name : superclass{
  ...
}
```

其中，`: superclass` 用于表示该类继承自哪个超类。子类将会继承超类中所有的字段以及方法。如下是一些例子：

```
class person { var name }
class student : person { var major }
```

在这个例子里，`person` 类拥有一个字段：`name`；`student` 类继承了 `person` 类，将会拥有两个字段：`name` 和 `major`。

RBQScript 不支持多重继承，即一个类继承多个类。

### 类型系统

RBQScript 的所有类都从一个根类 `object` 派生出来，所有对象都是 `object` 的类型都是子类。请注意，非对象的原生类型均不是 `object`。例如如下代码：

```
class person {}
class student : person {}
f = new student()
g = new person()
Console.print(f is student, f is person, f is object)
Console.print(g is student, g is person, g is object)
Console.print(0 is number, 0 is object, [] is object)
```

这段代码将输出：
```
true true true
false true true
true false true
```

对以上代码的解释如下：

- `f` 是 `student` 对象，因此 `f is student` 是成立的。同时，因为 `student` 是 `person` 的子类，因此 `f is person` 也成立。同理，`f is object` 也成立。
- `g` 是 `person` 对象，因此 `g is person` 是不成立的。其余两句和 `f` 的判断方式相同。
- 0 是一个数字，因此 `0 is number` 是成立的，而因为内置类型不属于对象，所以 `0 is object` 是不成立的。
- 数组类型也是对象，因此 `[] is object` 成立。

### 构造对象

RBQScript 提供 `new` 作为构造对象的标识符。其格式为：

```
new name(value1, value2, ...)
```

以上一小节 `student` 的例子为基础，下面是一些构造的例子：

```
new student()
new student('Alice','Math')
new student('Bob')
```

第一行构造了一个 `student` 对象，它的一切字段都是未初始化的值（即默认值 undefined）；接下来的两行是带参数的构造函数，具体在下面讲述。

### 构造函数

RBQScript 的构造函数语法如下：

```
class name{
  constructor(arg1,arg2,...){
    ...
  }
}
```

声明了构造函数之后，RBQScript 将在构造对象的时候调用对应的构造函数。

同一个类可以有**多个**构造函数，RBQScript 将**根据参数数量**在运行时选择对应的一个。如果不存在对应参数数量的构造函数，RBQScript 将会报告错误。例如，如下代码：

```
class pair{
  var x,y
  constructor(x) {this.x=x; this.y=0;}
  constructor(x,y) {this.x=x; this.y=y;}
}
new pair()
new pair(1)
new pair(2,3)
new pair(4,5,6)
```

当调用 `new pair(1)` 的时候，将会选择第一个构造函数；当调用 `new pair(2,3)` 时，将会选择第二个构造函数。而最后一行将会报告错误，因为在类中没有 3 个参数的构造函数。

请注意，RBQScript 会默认提供一个**不含任何参数**，但是什么都不做的构造函数。所以 `new pair()` 不会报告错误。


### 方法内访问字段

为了避免外围变量名与对象内字段冲突的问题，RBQScript 提供了 `this` 关键字以帮助区分。如果使用了 `this` 关键字，将会访问自身的字段。如下代码：

```
x=5
class foo{
  var x
  constructor(x){this.x=x}
  function look(){
    Console.print(x,this.x)
  }
}
f=new foo(10)
f.look()
```

运行以上代码将会输出 `5 10`。原因在于第一个 `x` 访问到的是外围的变量 `x`，即 5；而第二个 `this.x` 访问到的是自身的 `x` 字段，即 10。

### 重载运算符

RBQScript 支持重载运算符。重载运算符可以避免冗长的方法调用（比如 `a.add(b)`），换来更简洁的语法和更高的开发效率。格式如下：

```
class pair{
  var x,y
  constructor(x,y) {this.x=x; this.y=y;}
  operator * (rhs:pair){
    return this.x*rhs.x + this.y*rhs.y
  }
}

new pair(1,2) * new pair(5,6)
```

重载了乘法运算符 `*` 之后，原本不能直接相乘的 `pair` 类就可以使用乘号 `*` 直接相乘。参数的类型限定不是必要的，但是**建议使用限定来限制参数类型**。

RBQScript 支持以下运算符的重载：

```
+(unary) -(unary)
+ - * / % 
> < >= <= == != 
& | ^ ~ >> <<
&& || ! or
```

当对应运算符被支持之后，如果存在对应的**赋值运算符**（如 `+` 对应 `+=`、`*` 对应 `*=`），也将自动被支持。
