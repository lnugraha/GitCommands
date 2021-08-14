# Table of Contents

## List of git commands that are frequently used

The following shell scripts list all functions that contain all git commands
1. **updateGitBranch.sh** - Push all commits to master repository
2. **newGitBranch.sh** - Create a new branch and push it straight to the remote repository
3. **deleteGitBranch.sh** - Delete a specific branch in a repository and push it to the remote repository (make sure that you have commited to the remote or stash, and are not in the to-be-deleted branch)

## New Git Commands via Tokens ##
```
git remote set-url origin https://<token_number_here>@github.com/lnugraha/repository_name.git
git push -u origin main
```

### Hard Reset Branch ###
```
git reset --hard <version_number>
```

### Add and Commit before Pushing to Remote Branch ###
```
git commit -am "Write your comments here!"
```

### Clone a Specific Branch of a Repository ###
```
git clone -b develop git@repository_full_address_here.git
```

## List of UNIX commands that are frequently used

### Check the last 25 commands ###
```
history | tail -25
```

### Check the last 25 commands that contained the aforementioned keyword ###
```
history | grep echo | tail -25
```

### Kill a specific running process ###
```
ps -au
kill -9 process_number_to_be_killed
```

## List of OSX command lines that can be helpful ##

### Enable or Disable Start-Up Chime (Pre macOS 11.0) ###
```bash
// Enable start-up chime
sudo nvram BootAudio=%01

// Disable start-up chime
sudo nvram BootAudio=%00
```

### Enable of Disable Power Chime (only when plugging MacBooks to a charging cable) ###
```bash
// Enable power chime
defaults write com.apple.PowerChime ChimeOnAllHardware -bool TRUE; open /System/Library/CoreServices/PowerChime.app & 

// Disable power chime
defaults write com.apple.PowerChime ChimeOnAllHardware -bool FALSE; killall PowerChime
```

### Listen to Power Chime ###
```bash
// This sound indicates that your MacBook is charging upon plugging in power cables
afplay /System/Library/CoreServices/PowerChime.app/Contents/Resources/connect_power.aif
```

### Enable or Disable Power On through Opening Lid ###
```bash
// Enable boot-up by lid-lifting (default configuration)
sudo nvram AutoBoot=%03

// Disable boot-up by lid-lifting 
sudo nvram AutoBoot=%00
```

### Remove shadow effect on screenshot ###
```bash
// Disable shadow effect
defaults write com.apple.screencapture disable-shadow -bool TRUE

// Enable shadow effect (default configuration)
defaults write com.apple.screencapture disable-shadow -bool FALSE
```
