##作业概述
| 这个作业属于哪个课程 | [软件工程](https://edu.cnblogs.com/campus/gdgy/CSGrade21-34) |
| :-----------------: | :---------------: |
| 这个作业要求在哪里| [个人项目](https://edu.cnblogs.com/campus/gdgy/CSGrade21-34/homework/13023) |
| 这个作业的目标 |初步了解软件开发流程  |


PSP
| PSP2.1                                  | Personal Software Process Stages | 预估耗时（分钟） | 实际耗时（分钟） |
| --------------------------------------- | -------------------------------- | :--------: | :--------: |
| Planning                                | 计划                               | 10       | 10       |
| · Estimate                              | · 估计这个任务需要多少时间                   | 10       | 10       |
| Development                             | 开发                               | 345      | 300      |
| · Analysis                              | · 需求分析 (包括学习新技术)                 | 120      | 293      |
| · Design Spec                           | · 生成设计文档                         | 20       | 12       |
| · Design Review                         | · 设计复审                           | 10       | 3        |
| · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范)           | 5        | 7        |
| · Design                                | · 具体设计                           | 20       | 13       |
| · Coding                                | · 具体编码                           | 40       | 23       |
| · Code Review                           | · 代码复审                           | 10       | 6        |
| · Test                                  | · 测试（自我测试，修改代码，提交修改）             | 120      | 43       |
| Reporting                               | 报告                               | 45       | 38       |
| · Test Report                           | · 测试报告                           | 15       | 24       |
| · Size Measurement                      | · 计算工作量                          | 10       | 6        |
| · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划                | 20       | 8        |
|                                         | · 合计                             | 400      | 448      |

需求分析

查重算法
使用python3、Java或c++语言设计一个论文查重算法：

 - 输入：两文本文件以及输出文件的绝对路径
 - 输出：文件2相对文件1的重复率

参数输入
程序通过命令行形式运行使用，共需要设定三个命令行参数：论文原文文件、抄袭版论文文件以及输出答案文件的绝对路径

输出格式
答案文件中输出的答案为浮点型，精确到小数点后两位


具体实现

查重率计算
利用动态规划计算出两篇论文连续的重复字符串长度，以其与论文总长作为查重率的计算依据

函数调用树
![](https://img2023.cnblogs.com/blog/3270551/202309/3270551-20230916230109117-2115768099.png)

程序流程
![](https://img2023.cnblogs.com/blog/3270551/202309/3270551-20230916225719640-1849542213.jpg)

核心代码
![](https://img2023.cnblogs.com/blog/3270551/202309/3270551-20230916225220023-1572829769.png)


性能测试
![](https://img2023.cnblogs.com/blog/3270551/202309/3270551-20230916230607726-70264720.png)
函数接口较为单一，无需改进


单元测试

测试代码
![](https://img2023.cnblogs.com/blog/3270551/202309/3270551-20230916234522872-1377922305.png)


异常处理
命令行参数输入错误
![](https://img2023.cnblogs.com/blog/3270551/202309/3270551-20230916234714406-1616141564.png)

原论文文件路径输入错误
![](https://img2023.cnblogs.com/blog/3270551/202309/3270551-20230916234913399-877830673.png)

抄袭论文文件路径输入错误
![](https://img2023.cnblogs.com/blog/3270551/202309/3270551-20230916235056855-1278107257.png)

答案文件路径输入错误
将在对应路径下自动新建一个对应名称的文件，并将查重率计算结果写入
![](https://img2023.cnblogs.com/blog/3270551/202309/3270551-20230916235535480-173490214.png)


项目改进

项目局限性
此项目的查重算法是根据两文本的最大公共子序列来进行查重率的计算的，这种方法无法对于使用不同的表达方式进行论文抄袭的情况识别率较低

改进方法
可更换为基于海明码距的查重算法
