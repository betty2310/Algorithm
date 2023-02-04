file_name := MaxFlow.cpp
file_name_without_extension := $(basename $(file_name))
data := data.txt

run: $(file_name)
	g++ $(file_name) --std=c++17 -o $(file_name_without_extension) && ./$(file_name_without_extension) < $(data)

clean:
	rm -f $(file_name_without_extension)