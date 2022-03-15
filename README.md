> ubuntu 显示网速，内存，cpu 状态信息
```sh
sudo add-apt-repository ppa:fossfreedom/indicator-sysmonitor 
sudo apt-get update
sudo apt-get install indicator-sysmonitor
# 在终端执行，ctrl c 即可，但是退出终端也会退出
indicator-sysmonitor &
# 安装完成会有一个对应的图标，点击图标即可
# 点击工具栏，监控的区域，选择 preference 设置软件
# 自动启动
# 设置第二个 tab 页中 Customize output 
cpu: {cpu} mem: {mem} N:{net}
```

# 软件包国内镜像源

[python 软件包](https://registry.npmmirror.com/binary.html?path=python/)


# 开源电子书
1. [pro git](https://git-scm.com/book/zh/v2) -- [笔记](notes/progit.md)
