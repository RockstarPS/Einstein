import pandas as pd

csv_file = pd.read_csv("Final_merged_csv.csv")
csv_file.to_html("Final.html")
html_file = csv_file.to_html()