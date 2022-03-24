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
