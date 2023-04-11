# 设计模式实例

## 1. 写在前面

- 笔者个人认为设计模式本身过于抽象，具体实现下来，可以反映到类、函数，甚至代码块上，不同的设计模式之间也可能会有部分概念重叠，但是如果能够遵循设计模式的思想（同时也是代码设计的思想吧，减少耦合，增强扩展性等等），并且搞清楚该设计模式的优缺点和解决的问题，同时基于实际业务或框架来运用，效果应该会更好。
- 笔者个人认为，设计模式是编程知识中最需要结合实际去认识的，它本身的概念还是过于抽象，特别是一些通过描述无法准确想象的设计模式，例如我们常听到的单例模式，相对来说直接理解起来难度也不大，但是像桥接模式相对理解起来就会比较费力。此外，一些设计模式概念的重叠也会影响我们的理解。
- 该篇内容初步预想是写的越简洁越好，便于理解，后续可能会继续扩展，但会保持由浅入深的布局。
- 以下笔者会尽量结合具体实例来介绍个人对各种设计模式的理解，但是由于笔者能力和经历有限，部分可能只能给出一个大致框架，但是会尽量给出一些实际的例子。如果有误，欢迎讨论。

## 2. 示例

### 1. 工厂模式 TODO

工厂模式下分为：简单工厂模式和工厂方法模式

#### 1.1 任务系统

1. 不同任务创建就是通过taskmgr创建的

### 2. 策略模式

- 个人认为策略模式主要分为两个步骤：注册和执行。

  - 对于注册，以python为例，一般是使用字典来注册，实现方式可以通过装饰器，也可以通过直接定义一个全局字典，相对来说前者可读性更高，代码更优美。
  - 对于执行，个人经历中比较多的情况是各个策略函数的入参是一致（一般我们也会在这种情况下考虑使用策略模式），此外还可以使用装饰器来实现各策略函数的公共部分。如果参数不一致，就需要使用到策略类了，通过策略类来存储封装需要用到的参数。

- 这里给出一个比较通用没有使用策略类的模板：（具体可以根据需求进行优化，例如不需要装饰器执行公共逻辑，或者使用装饰器来注册，或者使用元类来注册，或者各函数的输入参数保持一致，或者使用策略类）

  ```python
  # 定义装饰器函数
  def strategy_decorator(strategy_func):
      def wrapper(*args, **kwargs):
          # 策略函数的共同逻辑
          # ...
          strategy_func(*args, **kwargs)
          # 策略函数的共同逻辑
          # ...
      return wrapper
  
  
  # 定义具体策略函数并应用装饰器
  @strategy_decorator
  def strategy_a():
      # 实现A类型的函数逻辑
      pass
  
  
  @strategy_decorator
  def strategy_b():
      # 实现B类型的函数逻辑
      pass
  
  
  @strategy_decorator
  def strategy_c():
      # 实现C类型的函数逻辑
      pass
  
  
  # 定义一个字典，将type与对应的函数关联起来
  strategy_dict = {
      'A': strategy_a,
      'B': strategy_b,
      'C': strategy_c,
  }
  
  
  # 定义客户端代码
  def execute_strategy(type):
      strategy_func = strategy_dict.get(type, None)
      if strategy_func:
          strategy_func()
      else:
          # 处理无法匹配type的情况
          pass
  ```


### 3. 装饰模式

- 个人认为装饰模式本质上是动态地添加功能。如果是将其用于“打补丁”，相较于直接修改原有逻辑，长期来说是较难维护的；但是如果是为了统一代码，抽离公共功能的实现，个人认为是易于扩展的，代码结构也很清晰，例如比较常见的添加一个logger装饰器。

- 具体实现可以是对一个函数进行装饰，也可以是对一个类进行装饰（一般也是对类里的方法去进行扩展），这里以python为例，给一个装饰函数的例子：（因为python中有现成的装饰器，实现起来还是很简单的）

  ```python
  # 定义装饰器函数
  def log_decorator(func):
      def wrapper(*args, **kwargs):
          print(locals())
          func(*args, **kwargs)
      return wrapper
  
  # 定义具体函数并应用装饰器
  @log_decorator
  def func(a):
      print(a)
  ```


### 4. 单例模式

- 单例模式也是一种比较好理解的设计模式：保证一个类只有一个实例，并且提供了访问该实例的全局访问点。

- 全局变量和单例：

  - 二者的区别很明显：全局变量不保证只有一个实例，而单例模式是保证只有一个实例的。
  - 个人认为部分全局变量本质上就是保持”单例“的，后续我会举例说明。

- 但根据个人开发的经历来说，感觉基本没有用到过单例设计模式，但会有单例的思想：

  - 导表数据。游戏开发中，各种数据是通过导表来设置的，服务器使用的导表数据在内存中也只有一份，并且这份数据不会进行修改，只进行读取，但使用的是全局变量的形式。
  - 各种管理器。一般会将各种管理器绑定在玩家对象上，本质上对每个玩家来说这些管理器也只有一个实例，个人觉得也是一种广义的单例。

- 下面以python为例给出一些单例模式的代码示例：

  - 函数装饰器：

    ```python
    def Singleton(cls):
    
        _instance = {}
    
        def inner():
            if cls not in _instance:
                _instance[cls] = cls()
            return _instance[cls]
    
        return inner
    
    
    @Singleton
    class MyClass:
        pass
    
    
    o1 = MyClass()
    o2 = MyClass()
    print(o1 is o2)  # True
    ```

  - 类装饰器：

    ```python
    class Singleton:
    
        def __init__(self, cls):
            self._cls = cls
            self._instance = {}
    
        def __call__(self, *args, **kwargs):
            if self._cls not in self._instance:
                self._instance[self._cls] = self._cls()
            return self._instance[self._cls]
    
    
    @Singleton
    class MyClass:
        pass
    
    
    o1 = MyClass()
    o2 = MyClass()
    print(o1 is o2)  # True
    ```

  - 元类metaclass：

    ```python
    class Singleton(type):
    
        def __init__(self, *args, **kwargs):
            self._instance = None
            super(Singleton, self).__init__(*args, **kwargs)
    
        def __call__(self, *args, **kwargs):
            if self._instance is None:
                self._instance = super().__call__(*args, **kwargs)
            return self._instance
    
    
    class MyClass(metaclass=Singleton):
        pass
    
    
    o1 = MyClass()
    o2 = MyClass()
    print(o1 is o2)  # True
    ```

  - 类变量➕重写\_\_new\_\_方法：

    ```python
    class MyClass:
    
        _instance = None
    
        def __new__(cls, *args, **kwargs):
            if cls._instance is None:
                cls._instance = super(MyClass, cls).__new__(cls, *args, **kwargs)
            return cls._instance
    
    
    o1 = MyClass()
    o2 = MyClass()
    print(o1 is o2)  # True
    ```

