**初始化**

进入到目标文件夹，git init 即初始化当前文件夹为 git 仓库。

或者 git init [仓库名称]



**分支**

查看分支

```
git branch -vv
# 查看 .git/HEAD 文件，展示当前检出分支
```

创建分支

```
git branch [分支名称]
```

创建并切换分支

```
git checkout -B [分支名称]
```

**删除分支**

想删除dev20181018分支
1 先切换到别的分支: git checkout dev20180927

2 删除本地分支： git branch -d dev20181018

3 如果删除不了可以强制删除，git branch -D dev20181018

4 有必要的情况下，删除远程分支(慎用)：git push origin --delete dev20181018

5 在从公用的仓库fetch代码：git fetch origin dev20181018:dev20181018

6 然后切换分支即可：git checkout dev20181018

删除本地分支`git branch -d 分支名` 或者`git branch -D 分支名` 强制删除分支

删除远程分支`git push origin --delete 分支名称`，不用添加`origin`，只用分支名称

查看当前分支提交日志`git log`， 查看简要日志`git log --oneline`， windows 过滤日志`git log --oneline | findstr '过滤文字'`

## 日志
`git log`查看commit日志。

`git log --oneline`只显示一行提交注释日志。

`git log -p`显示修改内容日志。

`git log -p -2`显示两次commit的修改内容日志。

`git log --stat`显示缩略的日志。

`git log --pretty=[oneline, short, full]`重新格式化显示日志。

`git log --pretty=format:"%h - %an, %ar : %s"`自定义格式化显示日志。

![image](https://user-images.githubusercontent.com/35592711/169473574-3dc4741c-614a-4e27-b24a-701695c4e6df.png)

`git log --graph`图形显示分支进度。

`git log --grep 过滤字符`过滤指定字符日志。

`git log --since=2.weeks`指定日期。

`git log -- path/to/file`指定文件的日志，同时可以组合上述参数。


## 回滚


# 第 10 章
创建一个新的对象，并从标准输入读入数据写入文件 .git/objects 中
```sh
echo 'hello' | git hash-object -w --stdin
# 返回一个 SHA-1 校验和 ce013625030ba8dba906f756967f9e9ca394464a
# 校验和的前两个字符用于命名子目录，余下的 38 个字符则用作文件名。
```
写入之后，查找对象
```sh
find .git/objects -type f
# 返回当前所有 hash 文件对象
# .git/objects/ce/013625030ba8dba906f756967f9e9ca394464a
# .git/objects/fb/100dfb30d9ab8d023c3410e7a71ee5704efc33
```
查看文件内容 使用 cat-file
```sh
git cat-file -p ce013625030ba8dba906f756967f9e9ca394464a
# hello
```


