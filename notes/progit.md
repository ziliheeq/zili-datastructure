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
