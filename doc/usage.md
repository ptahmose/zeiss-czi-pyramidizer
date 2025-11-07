
# Documentation for `czi-pyramidizer.exe`

## Overview
`czi-pyramidizer.exe` is a command-line tool designed for generating pyramids in CZI files.  
This tool reads a source CZI file, creates an image pyramid, and writes the pyramid along with the original image data into a new destination CZI file.

---

## Usage
```bash
czi-pyramidizer.exe [OPTIONS]
```

---

## Version
Current version: **0.1.0**

---

## Options

### General Options
- **`-h, --help`**  
  Displays help information and exits.

- **`--version`**  
  Prints extended version information, including supported operations and available stream-classes, then exits.

### Input/Output Options
- **`-s, --source TEXT`**  
  Specifies the URI of the source CZI file.

- **`-d, --destination TEXT`**  
  Specifies the URI of the destination CZI file.

- **`-o, --overwrite`**  
  Overwrites the destination file if it already exists.

### Stream Configuration
- **`--source-stream-class STREAMCLASS`**  
  Specifies the stream class used for reading the source CZI file. If not provided, the default file-reader stream class is used.  
  Run with `--version` to view available stream-classes.  
  Possible stream-classes include:  
  - `curl_http_inputstream`  
  - `azure_blob_inputstream`  
  - `windows_file_inputstream` 
  - `pread_file_inputstream`
  - `c_runtime_file_inputstream`

- **`--propbag-source-stream-creation PROPBAG`**  
  Specifies a JSON-formatted property bag for stream creation when reading the source CZI file.

### Pyramid Generation Options
- **`-n, --mode-of-operation MODE`**  
  Defines the mode of operation:  
  - `IfNeeded` (default): Generates a pyramid only if it's not already present in the source.  
  - `Always`: Always generates a new pyramid, discarding any existing one.

- **`-m, --max_top_level_pyramid_size MAX_TOP_LEVEL_PYRAMID_SIZE`**  
  Sets the maximum size (in pixels) of the top-level pyramid tile. Defaults to **1024**.

- **`-t, --tile_size TILE_SIZE`**  
  Specifies the extent (in pixels) of pyramid tiles. Defaults to **1024**.

- **`-p, --threshold-for-pyramid THRESHOLD_SIZE`**  
  Defines the size threshold (in pixels) for requiring a pyramid. If the image is smaller than this size, no pyramid is created. Defaults to **4096**.

### Compression Options
- **`-c, --compressionopts COMPRESSIONOPTIONS`**  
  Configures the compression for pyramid sub-blocks.  
  - If not provided, the compression mode is derived from the source document.  
  - Format: `"compression_method: key=value; ..."`  
  - Examples:  
    - `"zstd0:ExplicitLevel=3"`  
    - `"zstd1:ExplicitLevel=2;PreProcess=HiLoByteUnpack"`  
    - `"uncompressed:"`  
    - `"jpgxr:"`

### Other Options
- **`-v, --verbosity VERBOSITYLEVEL`**  
  Controls the verbosity level of console output. Acceptable values are between **0** (minimal output) and **5** (most detailed).

- **`-b, --background-color COLOR`**  
  Specifies the background color for the pyramid. Options:  
  - `black` or `0`  
  - `white` or `1`  
  - `auto` (auto-detect from source document).

- **`--check-only`**  
  Checks whether the source CZI already contains a pyramid and exits without making changes.

---

## Exit Codes

- **0**: Operation completed successfully or no pyramid is needed (in `--check-only` mode).
- **1**: Generic failure.
- **10**: A pyramid is needed but not present in the source file (in `--check-only` mode).
- **11**: No pyramid is required, or it is already present.
- **99**: Command-line arguments could not be parsed correctly.

---

## Examples

### Generate a Pyramid
```bash
czi-pyramidizer.exe -s input.czi -d output.czi
```

### Force Pyramid Creation
```bash
czi-pyramidizer.exe -s input.czi -d output.czi -n Always
```

### Use Compression
```bash
czi-pyramidizer.exe -s input.czi -d output.czi -c "zstd0:ExplicitLevel=3"
```

### Check for Existing Pyramid
```bash
czi-pyramidizer.exe -s input.czi --check-only
```

---

## Version and Stream Information
Running with `--version` displays additional details:
```bash
czi-pyramidizer.exe --version
```

---

## Additional Notes

