<img src="./img/icon.png" width="300px" />

# Helios

Helios is a small key-value database written in C.

It stores data in a simple text file using this format:

```text
key    value
```

Values can be JSON strings.

Example:

```text
1    {"name":"kali"}
2    {"name":"John"}
```

## Features

- Append-only storage
- Integer keys
- JSON/text values
- Retrieve the latest value for a key
- Simple command-line interface

## Build

```bash
gcc main.c db.c -o helios
```

## Usage

Store a value:

```bash
./helios set 1 '{"name":"kali"}'
```

Retrieve it:

```bash
./helios get 1
```

Example output:

```text
1    {"name":"kali"}
```

If the same key is written again, Helios returns the latest value.

```bash
./helios set 1 '{"name":"John"}'
./helios get 1
```

Output:

```text
1    {"name":"John"}
```



