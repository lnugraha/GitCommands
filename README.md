# List of git commands that are frequently used

The following shell scripts list all functions that contain all git commands
1. **updateGitBranch.sh** - Push all commits to master repository
2. **newGitBranch.sh** - Create a new branch and push it straight to the remote repository
3. **deleteGitBranch.sh** - Delete a specific branch in a repository and push it to the remote repository (make sure that you have commited to the remote or stash, and are not in the to-be-deleted branch)

## Hard Reset Branch ##
```
git reset --hard <version_number>
```

## Add and Commit before Pushing to Remote Branch ##
```
git commit -am "Write your comments here!"
```

## Clone a Specific Branch of a Repository ##
```
git clone -b develop git@repository_full_address_here.git
```

# List of UNIX commands that are frequently used

## Check the last 25 commands ##
```
history | tail -25
```

## Check the last 25 commands that contained the aforementioned keyword ##
```
history | grep cp | tail -25
```
