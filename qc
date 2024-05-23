#!/bin/zsh

# 默认目录
default_directory="/home/zzx/code/LeetCode"
today_only=false

# 检查参数
while [[ $# -gt 0 ]]; do
    case $1 in
        -t|--today)
            today_only=true
            shift
            ;;
        *)
            directory=$1
            shift
            ;;
    esac
done

# 如果没有传递目录参数，则使用默认目录
directory=${directory:-$default_directory}

# 检查目录是否存在
if [[ -d $directory ]]; then
    if $today_only; then
        # 获取当天日期
        current_date=$(date "+%Y-%m-%d")
        # 使用find命令统计当天的.cpp文件数量
        cpp_count=$(find $directory -type f -name "*.cpp" -newermt "$current_date" ! -newermt "$current_date + 1 day" | wc -l)
        echo "The total number of questions completed today is: $cpp_count"
        exit 0
    else
        # 使用find命令统计.cpp文件数量
        cpp_count=$(find $directory -type f -name "*.cpp" | wc -l)
        echo "The total number of questions completed is: $cpp_count"
    fi
else
    echo "The directory '$directory' does not exist."
    exit 1
fi

# 进入目录
cd $directory

# 检查是否是git仓库
if ! git rev-parse --git-dir > /dev/null 2>&1; then
    echo "This is not a git repository."
    exit 1
fi

# 获取第一条commit的日期
commit_date=$(git log --format="%ai" --reverse | head -n 1 | awk '{print $1}')

# 获取当前日期
current_date=$(date "+%Y-%m-%d")

# 计算日期差（以秒为单位）
start_date=$(date -d "$commit_date" +%s)
end_date=$(date -d "$current_date" +%s)
seconds_diff=$((end_date - start_date))

# 计算日期差（以天为单位）
days_diff=$(echo "scale=0; $seconds_diff / (24*60*60)" | bc)

# 输出结果
echo "The first commit was made on: $commit_date"

# 计算日均做题数
average_per_day=$(echo "scale=2; ($cpp_count/1) / ($days_diff/1)" | bc)
echo "Average questions completed per day: $average_per_day"
