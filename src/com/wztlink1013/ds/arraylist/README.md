
## 检验是否回收了没用的内存
### 提醒JVM进行垃圾回收
```
System.gc();
```
### “析构函数”
```
protected void finalize() throwsable {
    super.finalize();
    System.out.println("Person - finalize");
}
```