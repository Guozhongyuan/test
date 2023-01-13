
- 由于bind只能有一个绑定的，收/发必须有一端绑定
- 两种方法
- 1. robots-push-connect-5555  mid-pull-bind-5555 mid-pub-bind-5556 robots-sub-connect-5556 一共需要两个端口，类似rosmaster
- 2. 每个robot-pub-bind, 每个robot-sub-connect，一共需要N个端口