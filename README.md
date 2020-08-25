# List of git commands that are frequently used

The following shell scripts list all functions that contain all git commands
1. **updateGitBranch.sh** - Push all commits to master repository
2. **newGitBranch.sh** - Create a new branch and push it straight to the remote repository
3. **deleteGitBranch.sh** - Delete a specific branch in a repository and push it to the remote repository (make sure that you have commited to the remote or stash, and are not in the to-be-deleted branch)

```
git reset --hard <version_number>

git commit -am "Write your comments here!"

git clone -b develop git@repository_full_address_here.git
```
