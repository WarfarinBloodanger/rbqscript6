# RBQScript 6

## 请注意，新版 RBQScript （指 6.0 及以上，下同）与旧版 RBQScript **不兼容**

在目前版本，RBQScript 所使用的语法是 JavaScript 的一个子集。完整语法因为太长了不写手册了（

### 启动方式

`rbq6 [options/files]`

- 如果只有一个参数，即 `rbq6 <file>`，将会把 `<file>` 当作一个字节码文件执行；
- 否则将会启动参数解析：`-c` 表示编译、`-r` 表示运行，如果不以 `-` 开头将会解释为输入文件。输出文件为**出现在参数列表中的第一个文件，后缀改为 `.rbq6`**。

### rbqup

配套提供了新版的 rbqup 程序，用来查看程序文件字节码，使用方式：`rbqup <file1> <file2>...`。

### 内置函数列表

| 函数名 | 签名 |返回值类型 | 说明 |
| :----------: | :----------: | :----------: | :----------: |
| `Console.print` | `(...)` | `number`|将参数依次输出，中间用一个空格隔开，返回输出的参数数量 |
| `Console.exit` | `(code=number)` | `number`|以 code 为返回码退出虚拟机 |
| `Console.read_number` | `()` |  `number`|读入一个实数 |
| `Console.read_string` | `()` |  `string`|读入一个字符串，以空白符为结束标志  |
| `Console.read_line` | `()` | `string`| 读入一个字符串，以换行符为结束标志  |
| `Console.getchar` | `()` |  `string`|读入单个字符  |
| `Console.eof` | `()` |  `true/false`|检查读入是否已经结束  |
| `Console.printf` | `(format=string,...)` | `string` | 以 format 作为格式化字符串，将其中形如 `{<idx>}` 的子串替换为附加参数中对应的字符串  |
| `Math.sin` | `(x=number)` |  `number`| 返回 sin(x)  |
| `Math.cos` | `(x=number)` |  `number`| 返回 cos(x)  |
| `Math.tan` | `(x=number)` |  `number`| 返回 tan(x)  |
| `Math.asin` | `(x=number)` |  `number`| 返回 asin(x)  |
| `Math.acos` | `(x=number)` |  `number`| 返回 acos(x)  |
| `Math.atan` | `(x=number)` |  `number`| 返回 atan(x)  |
| `Math.atan2` | `(x=number,y=number)` |  `number`| 返回 atan2(x,y)  |
| `Math.exp` | `(x=number)` |  `number`| 返回 exp(x)  |
| `Math.log` | `(x=number)` |  `number`| 返回 log(x)  |
| `Fileio.open` | `(name=string,mode=string)` |  `number`|打开名为 `name` 的文件，使用 `mode` 作为打开格式字符串，返回文件句柄 _【1】_ |
| `Fileio.read_number` | `(handle=number)` |  `number`| 从 handle 指向的文件中读入一个实数 |
| `Fileio.read_string` | `(handle=number)` |  `string`|从 handle 指向的文件中读入一个字符串，以空白符为结束标志  |
| `Fileio.read_line` | `(handle=number)` | `string`| 从 handle 指向的文件中读入一个字符串，以换行符为结束标志  |
| `Fileio.write` | `(handle=number,...)` | `string`| 从 handle 指向的文件中写入值，返回写入的值的数量 |
| `Fileio.close` | `(handle=number)` | `number`| 关闭 handle 句柄 |
| `Fileio.eof` | `(handle=number)` |  `true/false`|检查 handle 指向的文件读入是否已经结束  |
| `System.clock` | `()` |  `number`| 返回程序开始到当前的 tick 数量  |
| `System.system` | `(cmd=string)` |  `number`| 以 cmd 为系统命令执行，返回结果  |
| `System.rand` | `()` |  `number`| 返回一个随机数  |
| `System.srand` | `(seed=number)` |  `number`| 设定随机数种子为 seed，返回设置的随机数种子  |
| `len` | `(seq=any)` |  `number`| 返回序列型对象 seq 的长度，若 seq 不是序列型对象则抛出异常  |
| `ascii` | `(s=string)` |  `number`| 返回给定字符串 s 第一个字符的 ascii 值 |
| `char` | `(c=number)` | `string`| 返回 c 对应的 ascii 字符  |

- 【1】 使用同 C 语言相同的打开格式描述符。即 `r/w/a/r+/w+/a+/rb/wb/ab/rb+/wb+/ab+`。
