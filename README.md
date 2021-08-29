# objc4

fork from [apple-opensource/objc4](https://github.com/apple-opensource/objc4) and compile success

# how to

## 1. Base SDK

- Settings Path
    1. project -> Build Settings -> Architectures -> Base SDK
    2. target -> anyone -> Build Settings -> Architectures -> Base SDK
- Action
    -  change from `macosx.internal` to `macOS`

## 2. Architectures


- Settings Path
    - target -> anyone -> Build Settings -> Architectures -> Architectures
- Action
    -  change to `Standard Architectures(64-bit Intel)`


## 3. add headers

- gather headers to `root/addon`
- update settings 
    - path: target -> objc -> Build Settings -> Header Serach Paths 
    - add `$(SRCROOT)/addon`

## 4. comment code

