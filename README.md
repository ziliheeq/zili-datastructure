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

> windows 安装 sshd

[参考](https://docs.microsoft.com/en-us/windows-server/administration/openssh/openssh_install_firstuse)
```powershell
Get-WindowsCapability -Online | Where-Object Name -like 'OpenSSH*'
# Install the OpenSSH Client
Add-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0

# Install the OpenSSH Server
Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0
# Start the sshd service
Start-Service sshd

# OPTIONAL but recommended:
Set-Service -Name sshd -StartupType 'Automatic'

# Confirm the Firewall rule is configured. It should be created automatically by setup. Run the following to verify
if (!(Get-NetFirewallRule -Name "OpenSSH-Server-In-TCP" -ErrorAction SilentlyContinue | Select-Object Name, Enabled)) {
    Write-Output "Firewall Rule 'OpenSSH-Server-In-TCP' does not exist, creating it..."
    New-NetFirewallRule -Name 'OpenSSH-Server-In-TCP' -DisplayName 'OpenSSH Server (sshd)' -Enabled True -Direction Inbound -Protocol TCP -Action Allow -LocalPort 22
} else {
    Write-Output "Firewall rule 'OpenSSH-Server-In-TCP' has been created and exists."
}
```

> 查看局域网外网地址
```
curl ifconfig.me
```

> 设置 linux 空闲登录时间

export TMOUT=900

> 配置 vscode [win] 插件位置

默认位置：用户名/.vscode/extensions/
```powershell
code --list-extensions
code --extensions-dir "新的插件位置"
# 剪切插件到新的路径下面
# 配置快捷方式
"E:\newwindows\Microsoft VS Code\Code.exe" --extensions-dir "E:\vscodeextension"
```

# 软件包国内镜像源

[python 软件包](https://registry.npmmirror.com/binary.html?path=python/)


# 开源电子书
1. [pro git](https://git-scm.com/book/zh/v2) -- [笔记](notes/progit.md)


# 学习推荐

[brendan gregg](https://www.brendangregg.com/books.html)

| 序号 | 分类 | 书籍 | 说明 |
| :--: | ---  |  --- | --- |
| 1  | C Programming |The C Programming Language 2nd Ed. - Brian W. Kernighan, Dennis M. Ritchie (Prentice Hall, 1988) | |
| 2  | C Programming | Expert C Programming - Peter van der Linden (Prentice Hall, 1994) | |




```
Systems Performance
Systems Performance 2nd edition - Brendan Gregg (Addison-Wesley, 2021)
BPF Performance Tools - Brendan Gregg (Addison-Wesley, 2019)
DTrace - Brendan Gregg, Jim Mauro (Prentice Hall, 2011)
Solaris Performance and Tools - Richard McDougall, Jim Mauro, Brendan Gregg (Prentice Hall, 2006)
System Performance Tuning, 2nd Ed. - Gian-Paolo D. Musumeci, Mike Loukides (O'Reilly, 2002)
Sun Performance and Tuning 2nd Ed. - Adrian Cockcroft, Richard Pettit (Prentice Hall, 1998)
System Performance Tuning, 1st Ed. - Mike Loukides (O'Reilly, 1990)
Language Performance
Java Performance: The Definitive Guide - Scott Oaks (O'Reilly, 2014)
Java Performance - Charlie Hunt, Binu John (Addison-Wesley, 2011)
Database Performance
High Performance MySQL, 3rd Ed. - Baron Schwartz, Peter Zaitsev, Vadim Tkachenko (O'Reilly, 2012)
High Performance MySQL, 2nd Ed. - Baron Schwartz, Peter Zaitsev, Vadim Tkachenko, ... (O'Reilly, 2008)
Optimizing Oracle Performance - Cary Millsap, Jeff Holt (O'Reilly, 2003)
Configuring & Tuning Databases on the Solaris Platform - Allan N. Packer (Prentice Hall, 2001)
Capacity Planning
The Art of Capacity Planning - John Allspaw (O'Reilly, 2008)
Scalable Internet Architectures - Theo Schlossnagle (Sams Publishing, 2006)
Configuration and Capacity Planning for Solaris Servers - Brian L. Wong (Prentice Hall, 1997)
Performance Modeling
The Practical Performance Analyst - Neil Gunther (McGraw Hill, 1997)
The Art of Computer Systems Performance Analysis - Raj Jain (Wiley, 1991)
OS Internals
Windows Internals, Part 1 - Pavel Yosifovich, Mark Russinovich, David Solomon, Alex Ionescu (Microsoft Press, 2017)
The Design and Implementation of the FreeBSD Operating System 2nd Ed - Marshall Kirk McKusick, George V. Neville-Neil, Robert N.M. Watson (Addison-Wesley, 2014)
Linux Kernel Development, 3rd Ed. - Robert Love (Addison-Wesley, 2010)
Operating Systems In Depth - Thomas W. Doeppner (Wiley, 2010)
Solaris Internals 2nd Ed. - Richard McDougall, Jim Mauro (Prentice Hall, 2006)
Mac OS X Internals - Amit Singh (Addison-Wesley, 2006)
Understanding the Linux Kernel, 3rd Ed. - Daniel P. Bovet, Marco Cesati Ph.D. (O'Reilly, 2005)
Linux Device Drivers, 3rd Ed. - Jonathan Corbet, Alessandro Rubini, Greg Kroah-Hartman (O'Reilly, 2005)
The Design and Implementation of the FreeBSD Operating System - Marshall Kirk McKusick, George V. Neville-Neil (Addison-Wesley, 2004)
Solaris Internals 1st Ed. - Richard McDougall, Jim Mauro (Prentice Hall, 2000)
Unix Internals - Uresh Vahalia (Prentice Hall, 1995)
The Magic Garden Explained - Berny Goodheart, James Cox (Prentice Hall, 1995)
The Design of the Unix Operating System - Maurice J. Bach (Prentice Hall, 1986)
Lions' Commentary on UNIX 6th Edition - John Lions (Annabooks, 1977)
Unix Administration
Unix and Linux System Administration Handbook - Evi Nemeth, Garth Snyder, ... (Prentice Hall, 2010)
Unix in a Nutshell - Arnold Robbins (O'Reilly, 2005)
Think Unix - Jon Lasser (Que, 2000)
Unix Hints & Hacks - Kirk Waingrow (Que, 1999)
Computer Security
Hacking Exposed - McClure, Scambray, Kurtz (McGraw-Hill Osborne, 2009)
The Cuckoo's Egg - Cliff Stoll (Gallery, 2005)
Secrets and Lies - Bruce Schneier (Wiley, 2004)
The Tao of Network Security Monitoring - Richard Bejtlich (Addison-Wesley, 2004)
The Art of Deception - Kevin Mitnick (Wiley, 2003)
Tangled Web - Richard Power (Que, 2000)
Cryptonomicon - Neal Stephenson (fiction, Avon, 2002)
Applied Cryptography - Bruce Schneier (Wiley, 1996)
Programming
The Art of Unix Programming - Eric S. Raymond (Addison-Wesley, 2003)
The Practice of Programming - Brian Kernighan, Rob Pike (Addison-Wesley, 1999)
The Unix Programming Environment - Brian Kernighan, Rob Pike (Prentice Hall, 1984)
The Mythical Man-Month - Frederick P. Brooks (Addison-Wesley, 1995/1975)

Perl Programming
Anything by Randal Schwartz
Shell Scripting
The AWK Programming Language - Alfred V. Aho, Brian W. Kernighan, Peter J. Weinberger (Addison Wesley, 1988)
IT History
UNIX: A History and a Memoir - Brian W Kernighan (independent, 2019)
Just For Fun - Linus Torvalds (Harper, 2002)
Dealers of Lightning - Michael A. Hiltzik (Harper, 2000)
In the Beginning was the Command Line - Neal Stephenson (William Morrow, 1999)
Nerds 2.0.1 A Brief History of the Internet - Stephen Segaller (TV Books, 1999)
Where Wizards Stay Up Late - Katie Hafner, Matthew Lyon (Simon & Schuster, 1998)
Accidental Empires - Robert X. Cringely (Harper, 1996)
Life With Unix - Don Libes, Sandy Ressler (Prentice Hall, 1989)
IT Other
Retrospectives Antipatterns - Aino Vonge Corry (Addison-Wesley, 2020)
Misc Favourites
Skunk Works - Ben R. Rich & Leo Janos (Black Bay Books, 1996)
The Worst Journey in the World - Apsley Cherry-Garrard (Penguin, 2006/1922)
Management
The Dilbert Principle - Scott Adams (Harper, 1997)
The No Asshole Rule - Robert I. Sutton (Business Plus, 2010)
Snakes in Suits - Paul Babiak, Robert D. Hare (Harper Business, 2007)

```

删除用户
userdel -r haha
