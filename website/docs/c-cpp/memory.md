---
sidebar_position: 1
title: Memory Guide
sidebar_label: Memory Guide
---

## Limit Memory Usage with `ulimit` Command

The following commands allow you to limit the memory usage for your processes. These limits are specified in kilobytes (KB) and are useful for setting constraints during development, particularly for ensuring your programs do not exceed certain memory thresholds. Here’s how you can set and verify these limits:

```bash
ulimit -v 65536     # Limit memory to 64 MB
ulimit -v 131072    # Limit memory to 128 MB
ulimit -v 262144    # Limit memory to 256 MB
ulimit -v 524288    # Limit memory to 512 MB
ulimit -v 1048576   # Limit memory to 1 GB
ulimit -v 2097152   # Limit memory to 2 GB
ulimit -v 4194304   # Limit memory to 4 GB
ulimit -v 8388608   # Limit memory to 8 GB
ulimit -v 16777216  # Limit memory to 16 GB
ulimit -v 33554432  # Limit memory to 32 GB
```

You may find more details in the `ulimit` manual page using the command:

```bash
man ulimit
```

### Verify Current Limits

To check the current resource limits, you can execute the following command:

```bash
ulimit -a
```

### Memory Limits Table

The following table provides a reference for memory limits in both megabytes (MB) and kilobytes (KB):

| Memory (MB) | Memory (KB) |
|--------------|--------------|
| 64 MB        | 65,536 KB    |
| 128 MB       | 131,072 KB   |
| 256 MB       | 262,144 KB   |
| 512 MB       | 524,288 KB   |
| 1 GB         | 1,048,576 KB |
| 2 GB         | 2,097,152 KB |
| 4 GB         | 4,194,304 KB |
| 8 GB         | 8,388,608 KB |
| 16 GB        | 16,777,216 KB|
| 32 GB        | 33,554,432 KB|
