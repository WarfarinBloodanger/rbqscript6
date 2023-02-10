# 值与变量

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

# 基本语法

## 运算符

RBQScript 支持一系列运算符。

- **数学运算符**，可执行数学运算：
- - `+ - * / %` 分别对应加、减、乘、除、取模运算（实数取模）。
- **位运算符**，可对数字的进行按位操作，**操作将会舍弃操作数的小数部分**：
- - `<< >>` 分别对应左移，右移运算符，将空余位用 0 填充。
- - `& | ~ ^` 分别对应按位与、按位或、按位取非（单元运算符）和按位异或。
- **逻辑运算符**，可进行逻辑运算，**除了 0、null 和 undefined 之外的值都将被视作 true**：
- - `&& || !` 分别对应逻辑与、逻辑或和逻辑非（单元运算符）。
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
- - `has` 判断存在，语法为 `value_set has value`，判断 `value_set` 中是否包含 `value` 这个值，以 `true` 或 `false` 返回结果。
- - `new` 构造对象，语法为 `new Class(field1=value1,field2=value2...)`。具体行为将在本文档的对应小节表述。

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
