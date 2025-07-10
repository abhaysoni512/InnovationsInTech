# flask_app/app.py
from flask import Flask, jsonify, render_template
import packet_capture
import pandas as pd

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/api/packet_stats")
def packet_stats():
    packets = packet_capture.capture_packets(50)
    df = pd.DataFrame([{
        "src_ip": p.src_ip,
        "dst_ip": p.dst_ip,
        "protocol": p.protocol,
        "src_port": p.src_port,
        "dst_port": p.dst_port
    } for p in packets])

    return jsonify({
        "total": len(df),
        "protocols": df["protocol"].value_counts().to_dict(),
        "top_src_ips": df["src_ip"].value_counts().head(5).to_dict(),
        "top_dst_ports": df["dst_port"].value_counts().head(5).to_dict()
    })

if __name__ == "__main__":
    app.run(debug=True)
