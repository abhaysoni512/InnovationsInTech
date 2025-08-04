import yt_dlp
import csv

playlist_url = "https://youtube.com/playlist?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&si=xn1OJBNlQWt-_Wob"

ydl_opts = {
    "extract_flat": True,  # Only extract metadata, do not download videos
    "quiet": True          # Optional: suppress output
}
with yt_dlp.YoutubeDL(ydl_opts) as ydl:
    info = ydl.extract_info(playlist_url, download=False)
    entries = info.get('entries', [])

    with open('yt_playlist.csv', 'w', newline='', encoding='utf-8') as file:
        csv_file = csv.writer(file)
        csv_file.writerow(['Title', 'URL'])
        for entry in entries:
            if entry:
                title = entry.get('title', 'N/A')
                url = f"https://www.youtube.com/watch?v={entry.get('id')}"
                csv_file.writerow([title, url])