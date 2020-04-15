#!/bin/zsh

############################################################
# Delete a new branch and push it to the remote repository #
############################################################ 

function delBranch(){
  if [[ $# -eq 0]]; then
    echo "Please specify the branch name that will be deleted";
  else:  
    git pull origin master;
    git branch -d $1;
    git push origin --delete $1;
  fi
}

delBranch $1
