class Solution {
public:
    string simplifyPath(string path) {
        std::stack<std::string> parsed_path;
        std::string folder;
        std::string answer;

        for (char& ch : path) {
            if (ch == '/') {
                if (folder.empty()) {
                    continue;
                } else {
                    if (folder == ".") {
                        folder.clear();
                    } else if (folder == "..") {
                        if (!parsed_path.empty()) {
                            parsed_path.pop();
                        }
                        folder.clear();
                    } else {
                        parsed_path.push(folder);
                        folder.clear();
                    }
                }
            } else {
                folder.push_back(ch);
            }
        }

        if (!folder.empty()) {
            if (folder == "..") {
                if (!parsed_path.empty()) {
                    parsed_path.pop();
                }
            } else if (folder != ".") {
                parsed_path.push(folder);
            }
        }

        std::stack<std::string> ihihihih;

        while (!parsed_path.empty()) {
            ihihihih.push(parsed_path.top());
            ihihihih.push("/");
            parsed_path.pop();
        }

        while(!ihihihih.empty()) {
            answer.append(ihihihih.top());
            ihihihih.pop();
        }

        if (answer.empty()) {
            answer = "/";
        }

        return answer;
    }
};