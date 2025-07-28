import sys
import os
import re
from collections import defaultdict

TABLE_HEADER = (
    "| Serial No | Folder Name                    | File Name                                    |\n"
    "|-----------|--------------------------------|----------------------------------------------|"
)

FOLDER_SEPARATOR = "\n|-----------|--------------------------------|----------------------------------------------|"

def natural_sort_key(filename):
    """Extract numeric prefix for natural sorting of filenames"""
    # Extract number from start of filename
    match = re.match(r'(\d+)', filename)
    if match:
        number = int(match.group(1))
        remainder = filename[match.end():]
        return (number, remainder)
    return (float('inf'), filename)  # Files without numbers come last

def get_relative_dir_and_file(filepath, root):
    """Normalize file path to ensure consistent folder names"""
    abs_path = os.path.abspath(filepath)
    root = os.path.abspath(root)
    rel_path = os.path.relpath(abs_path, root)
    parts = rel_path.split(os.sep)
    
    if len(parts) == 1:  # File in root directory
        return "", parts[0]
    else:  # File in subdirectory
        return parts[0], parts[-1]

def read_table(md_path):
    """Read existing entries from README.md"""
    entries = defaultdict(set)
    if not os.path.exists(md_path):
        return entries
        
    with open(md_path, "r") as f:
        for line in f:
            if "|" not in line or "Serial No" in line or "-" in line:
                continue
            parts = [p.strip() for p in line.split("|")]
            if len(parts) >= 4:
                folder = parts[2].strip()
                filename = parts[3].strip()
                if folder and filename:  # Only add if both exist
                    entries[folder].add(filename)
                elif filename:  # File belongs to last known folder
                    last_folder = max(entries.keys()) if entries else ""
                    entries[last_folder].add(filename)
    return entries

def write_table(md_path, folder_files):
    """Write the table with proper grouping and natural sorting"""
    with open(md_path, "w") as f:
        f.write(TABLE_HEADER)
        
        serial = 1
        # Sort folders but ensure root directory (empty string) comes first
        folders = sorted(folder_files.keys(), key=lambda x: (x == "", x))
        
        for i, folder in enumerate(folders):
            # Sort files within the folder using natural sort
            files = sorted(folder_files[folder], key=natural_sort_key)
            
            for j, file in enumerate(files):
                # Only show folder name for first file in group
                display_folder = folder if j == 0 else ""
                f.write(f"\n| {serial:<9} | {display_folder:<30} | {file:<45} |")
                serial += 1
            
            # Add separator between folders
            if i < len(folders) - 1:
                f.write(FOLDER_SEPARATOR)

def main():
    if len(sys.argv) != 2:
        print("Usage: python update_readme.py <file_path>")
        sys.exit(1)

    file_path = sys.argv[1]
    root_dir = os.path.dirname(os.path.abspath(__file__))
    md_path = os.path.join(root_dir, "README.md")

    # Get folder and file from the new entry
    folder, filename = get_relative_dir_and_file(file_path, root_dir)
    
    # Read existing entries
    folder_files = read_table(md_path)
    
    # Add new entry
    folder_files[folder].add(filename)
    
    # Write updated table
    write_table(md_path, folder_files)

if __name__ == "__main__":
    main()
