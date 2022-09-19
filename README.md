## Problem:

Design APIs to travel all solutions, which are met the requirements of all
limitations.

- Support to add variables with name.
- Support to add variables with varargs.
- Support to add limitations for collection.
- Support to travel all solutions.

You should implement follow functions:
```
- add_variable(name, val, ...)
- add_limit(func)
- travel_solution(func)
```

We implement a demo for this problem, but it just a demo. You **should NOT** be
restricted by this demo.


### Limitation;

**Limit 1**

The type of variables is Int.

**Limtt 2**

You can suppose all limits don't have bugs.


## Requirement:

- Use git to manage your codes.
- Obey linux-kernel coding style.
  - https://www.kernel.org/doc/html/v4.10/process/coding-style.html
- Create a unit test for regression.
**这是一个更通用的写法，跳出结果变为val参数为0但这也会让参数中不能有0的存在，但当参数自动获取时，出现0即可表示获取完毕**