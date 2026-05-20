# SocialNode

A simple social media simulation project written in C using Linked Lists and Pointers.

## Features
- Create users
- Add users to the system
- Follow other users
- Display following list
- Display followers list
- Show all users

## Structures Used

### User
```c
struct User{
    int user_id;
    char user_name[50];
    int user_age;

    struct FollowNode *following;
    struct FollowNode *followers;

    struct User *next;
};
```

### FollowNode
```c
struct FollowNode{
    struct User *user;
    struct FollowNode *next;
};
```

## Compile

```bash
gcc social.c -o social
```
## Concepts Used
- Structures
- Pointers
- Linked Lists
- Dynamic Memory Allocation
- Self-referential Structures

Created by: Osama
