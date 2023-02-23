# RBQScript 6

## 请注意，新版 RBQScript （指 6.0 及以上，下同）与旧版 RBQScript **不兼容**

遵循 GNU 3.0 开源协议。

请在对应仓库中下载源代码并自行编译出程序。作者编译器版本及参数：TDM-GCC 4.9.2 64-bit Release，开启 `std=c++11`。

### rbq6

`rbq6 [options/files]`

- 如果只有一个参数，即 `rbq6 <file>`，将会把 `<file>` 当作一个字节码文件执行；
- 否则将会启动参数解析：`-c` 表示编译、`-r` 表示运行，如果不以 `-` 开头将会解释为输入文件。输出文件为**出现在参数列表中的第一个文件，后缀改为 `.rbq6`**。

### rbqup

配套提供了新版的 rbqup 程序，用来查看程序文件字节码，使用方式：`rbqup <file1> <file2>...`。

### 内置方法列表

| 函数名 | 签名 |返回值类型 | 说明 |
| :----------: | :----------: | :----------: | :----------: |
| `Console.print` | `(...)` | `number`|将参数依次输出，中间用一个空格隔开，返回输出的参数数量 |
| `Console.read_number` | `()` |  `number`|读入一个实数 |
| `Console.read_string` | `()` |  `string`|读入一个字符串，以空白符为结束标志  |
| `Console.read_line` | `()` | `string`| 读入一个字符串，以换行符为结束标志  |
| `Console.getchar` | `()` |  `string`|读入单个字符  |
| `Console.eof` | `()` |  `true/false`|检查读入是否已经结束  |
| `Console.printf` | `(format=string,...)` | `string` | 以 format 作为格式化字符串，将其中形如 `{<idx>}` 的子串替换为第 idx 个参数，并输出  |
| `Math.sin` | `(x=number)` |  `number`| 返回 sin(x)  |
| `Math.cos` | `(x=number)` |  `number`| 返回 cos(x)  |
| `Math.tan` | `(x=number)` |  `number`| 返回 tan(x)  |
| `Math.asin` | `(x=number)` |  `number`| 返回 asin(x)  |
| `Math.acos` | `(x=number)` |  `number`| 返回 acos(x)  |
| `Math.atan` | `(x=number)` |  `number`| 返回 atan(x)  |
| `Math.atan2` | `(x=number,y=number)` |  `number`| 返回 atan2(x,y)  |
| `Math.exp` | `(x=number)` |  `number`| 返回 exp(x)  |
| `Math.log` | `(x=number)` |  `number`| 返回 log(x)  |
| `Math.random` | `()` |  `number`| 返回一个随机实数，介于 0 和 1 之间  |
| `Math.set_random_seed` | `(seed=number)` |  `number`| 设定随机数种子为 seed，返回设置的随机数种子  |
| `Fileio.open` | `(name=string,mode=string)` |  `number`|打开名为 `name` 的文件，使用 `mode` 作为打开格式字符串，返回文件句柄 _【1】_ |
| `Fileio.read_number` | `(handle=number)` |  `number`| 从 handle 指向的文件中读入一个实数 |
| `Fileio.read_string` | `(handle=number)` |  `string`|从 handle 指向的文件中读入一个字符串，以空白符为结束标志  |
| `Fileio.read_line` | `(handle=number)` | `string`| 从 handle 指向的文件中读入一个字符串，以换行符为结束标志  |
| `Fileio.write` | `(handle=number,...)` | `string`| 从 handle 指向的文件中写入值，返回写入的值的数量 |
| `Fileio.close` | `(handle=number)` | `number`| 关闭 handle 句柄 |
| `Fileio.eof` | `(handle=number)` |  `true/false`|检查 handle 指向的文件读入是否已经结束  |
| `System.clock` | `()` |  `number`| 返回程序开始到当前的 tick 数量  |
| `System.system` | `(cmd=string)` |  `number`| 以 cmd 为系统命令执行，返回结果  |
| `System.abort` | `(msg=string)` |  `number`| 以 msg 为错误信息抛出异常  |
| `System.exit` | `(code=number)` | `number`|以 code 为返回码退出虚拟机 |

### 内置函数列表

| 函数名 | 签名 |返回值类型 | 说明 |
| :----------: | :----------: | :----------: | :----------: |
| `len` | `(seq=string/reference)` |  `number`| 返回 seq 的长度，若 seq 不是字符串或指向的不是列表则抛出异常  |
| `ascii` | `(s=string)` |  `number`| 返回给定字符串 s 第一个字符的 ascii 值 |
| `char` | `(c=number)` | `string`| 返回 c 对应的 ascii 字符  |
| `type` | `(val=any)` | `string`| 返回 val 的类型名  |
| `string` | `(val=any)` | `string`| 将 val 字符串表示 |
| `number` | `(val=string/number)` | `number`| 将 val 转化为实数 number 后返回。将在第一个非法字符停止。 |
| `dec` | `(hexstr=string)` | `number`| 将 hexstr 转化为十进制的结果返回。必须以 `0x` 或 `0X` 开头。遇到非法字符将会抛出异常。 |
| `hex` | `(decnum=number)` | `number`| 将 decnum 转化为十六进制字符串的结果返回。 |
| `int_to_str` | `(val=number,base=number)` | `string`| 将 val 转化为 base 进制字符串的结果返回。base 为 -1、0、1 或者绝对值大于 36 的数时抛出异常 |
| `str_to_int` | `(val=string,base=number)` | `string`| 将 base 进制字符串 val 转化为十进制的结果返回。出现非法字符、base 为 -1、0、1 或者绝对值大于 36 的数时抛出异常 |
| `utf8_string` | `(seq=reference)` | `string`| 返回将 seq 指向的对象（必须是列表）的每个元素以 UTF-8 编码后连接起来的字符串。 |
| `utf8_string` | `(...)` | `string`| 返回将每个参数以 UTF-8 编码后连接起来的字符串。 |
| `keys` | `(ref:reference)` | `reference`| 返回一个数组，保存了 `ref` 内部所有的键。|
| `values` | `(ref:reference)` | `reference`| 返回一个数组，保存了 `ref` 内部所有的值。|

- 【1】 使用同 C 语言相同的打开格式描述符。即 `r/w/a/r+/w+/a+/rb/wb/ab/rb+/wb+/ab+`。

### 内置类型方法列表

| 类.方法 | 签名 |返回值类型 | 说明 |
| :----------: | :----------: | :----------: | :----------: |
| `string.substring` | `([from=number],[to=number])` | `string`| 返回 this 在 from 到 to 之间的子串（闭区间）。若 from 和 to 不在字符串下标范围内，将会修正为 0 或 this 的最后一个下标。 |
| `string.format` | `(...)` | `string`| 返回将 this 作为格式化字符串，将其中形如 `{<idx>}` 的子串替换为第 idx 个参数的结果 ||
| `string.repeat` | `(times=number)` | `string`| 返回将 this 重复 times 次的结果 |
| `string.replace` | `(target=string,repl=string)` | `string`| 返回 this 中第一个 target 子串替换为 repl 后的结果 |
| `string.split` | `(target=string)` | `reference`| 返回将 this 用 target 作为分隔符后分隔出的所有元素组成的列表 |
| `string.index` | `(target=string,[from=number])` | `number`| 返回 this 中从 from（默认为 0）开始的第一个 target 子串的起始下标。如果找不到返回 -1 |
| `string.substr` | `(from=number,length=number)` | `string`| 返回 this 中从 from 开始的长度为 length 的子串。若 from 和 length 不在字符串下标范围内，将会修正|
| `string.to_upper` | `()` | `string`| 返回将字符串中所有小写字母转为大写后的结果 |
| `string.to_lower` | `()` | `string`| 返回将字符串中所有大写字母转为小写后的结果 |
| `string.starts_with` | `(prefix=string)` | `true/false`| 如果 this 以 prefix 开头，返回 true，否则返回 false |
| `string.ends_with` | `(suffix=string)` | `true/false`| 如果 this 以 suffix 结尾，返回 true，否则返回 false |
| `string.trim` | `()` | `string`| 返回将字符串开头结尾的空白符去除后的结果 |


| 类.方法 | 签名 |返回值类型 | 说明 |
| :----------: | :----------: | :----------: | :----------: |
| `reference.indice` | `()` | `reference`| 返回 this 指向的对象中存在的所有下标|
| `reference.sort` | `()` | `reference`| 返回 this 指向的对象中所有元素按值排序后的结果。this 必须指向列表 |
| `reference.reverse` | `()` | `reference`| 返回 this 指向的对象中所有元素前后倒置的结果。this 必须指向列表 |
| `reference.length` | `()` | `reference`| 返回 this 指向的对象的长度。this 必须指向列表|
| `reference.push` | `(...)` | `any`| 将所有参数依次追加到 this 指向的对象的尾部，并返回最后一个参数。this 必须指向列表  |
| `reference.pop` | `()` | `any`| 将 this 指向的对象的的最后一个元素弹出，并返回这个值。this 必须指向列表  |
