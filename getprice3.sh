DAY=` date "+%d" `
MONTH=` date "+%m" `
SYMBOL=$1
YEAR=$2

url="https://bigcharts.marketwatch.com/historical/default.asp?symb=$SYMBOL&closeDate=$MONTH%2F$DAY%2F$YEAR"

output=$(wget -qO - "$url")

output=$(echo "$output" | tr -d "\r" | tr -d "\n")

final=$(echo "$output"| sed "s|^.*Closing Price:</th>||g" | sed "s|</td>.*$|\n|g" | sed "s|<td>||g")

echo $final
