# box2d

This is a `build2` package repository for [Box2D](https://github.com/erincatto/box2d),
a 2D physics engine for games written in portable C17.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libbox2d` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libbox2d/PACKAGE-README.md) file.

## Development

The development setup for `box2d` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules https://github.com/build2-packaging/box2d.git
cd box2d

bdep init -C @gcc c config.c=gcc
bdep update
bdep test
```
