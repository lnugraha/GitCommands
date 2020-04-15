#!/bin/zsh

######################################## 
# Usage: ./newGitBranch.sh branch_name #
######################################## 

function newBranch(){
  if [[ $# -eq 0 ]]; then
    # using default branch name
    git checkout -b temporary-branch;
    echo "temporary-branch has been created";
    git push -u origin temporary-branch;
  else
    # using your own branch name
    git checkout -b $1;
    echo "$1 branch has been created";
    git push -u origin $1;
  fi
}

newBranch $1

