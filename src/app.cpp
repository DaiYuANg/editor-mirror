//
// Created by 戴宇昂 on 2022/7/7.
//

#ifndef WX_PRECOMP

#include <wx/wx.h>
#include "app.h"
#include "frame.h"
#include <stdio.h>
#include <sqlite3.h>
#include <toml++/toml.h>

#endif


namespace fs = std::filesystem;

bool App::OnInit() {
    //test  sqlite
    sqlite3 *db;
    char *zErrMsg = nullptr;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (false);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    sqlite3_close(db);
    toml::table tbl;
    try {
        tbl = toml::parse_file("conf/global.toml");
        std::cout << tbl << "\n\n";
        std::cout << "Current working directory: " << fs::current_path() << '\n';
    }
    catch (const toml::parse_error &err) {
        std::cerr
                << "Error parsing file '" << *err.source().path
                << "':\n" << err.description()
                << "\n  (" << err.source().begin << ")\n";
        return true;
    }
    auto *frame = new EditorFrame();
    frame->SetTitle("editor by daiyuang");
    frame->Show(true);
    return true;
}