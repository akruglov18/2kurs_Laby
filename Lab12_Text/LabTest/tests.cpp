#include<gtest.h>
#include"Text.h"

TEST(Text, can_create_0) {
  ASSERT_NO_THROW(Text t());
}

TEST(Text, can_create_1) {
  ASSERT_NO_THROW(Text t("Prishli"));
}

TEST(TextIter, go_next_char_0) {
  Text t("Prishli st");
  TextIter i = t.GetRoot();
  i.GoNextChar();
  ASSERT_EQ(i.Get()->getC(), 'P');
}

TEST(TextIter, go_next_char_1) {
  Text t("Prishli st");
  TextIter i = t.GetRoot();
  while(i.Get()->getC() != ' ')
    i.GoNextChar();
  i.GoNextChar();
  ASSERT_EQ(i.Get()->getC(), 's');
}


TEST(TextIter, go_next_char_2) {
  Text t("Prishli studenti.");
  string s = "Prishli studenti.";
  TextIter i = t.GetRoot();
  bool ok = true;
  int j = 0;
  while (i.GoNextChar()) {
    if (i.Get()->getC() != s[j]) {
      ok = false;
      break;
    }
    j++;
  }
  ASSERT_EQ(ok, true);
}

TEST(TextIter, can_go_next_char_0) {
  Text t("Prishli st");
  TextIter i = t.GetRoot();
  while (i.Get()->getC() != ' ')
    i.GoNextChar();
  ASSERT_EQ(i.GoNextChar(), true);
}

TEST(TextIter, can_go_next_char_1) {
  Text t("Prishli st");
  TextIter i = t.GetRoot();
  while (i.Get()->getC() != ' ')
    i.GoNextChar();
  i.GoNextChar();
  i.GoNextChar();
  ASSERT_EQ(i.GoNextChar(), false);
}

TEST(TextIter, go_next_0) {
  Text t("Prishli studenti.");
  TextIter i = t.GetRoot();
  for (int c = 0; c < 6; c++) {
    i.GoNext();
  }
  ASSERT_EQ(i.Get()->getC(), 'h');
}

TEST(TextIter, go_next_1) {
  Text t("abcdefg htudenti.");
  TextIter i = t.GetRoot();
  for (int c = 0; c < 9; c++) {
    i.GoNext();
  }
  ASSERT_EQ(i.Get()->getC(), ' ');
}

TEST(TextIter, go_next_2) {
  Text t("abcdefg htudenti.");
  TextIter i = t.GetRoot();
  for (int c = 0; c < 13; c++) {
    i.GoNext();
  }
  ASSERT_EQ(i.Get()->getC(), 'u');
}

TEST(TextIter, can_go_next_0) {
  Text t("abcdefg htudenti.");
  TextIter i = t.GetRoot();
  for (int c = 0; c < 9; c++) {
    i.GoNext();
  }
  ASSERT_EQ(i.GoNext(), true);
}

TEST(TextIter, can_go_next_1) {
  Text t("abcdefg htudenti.");
  TextIter i = t.GetRoot();
  for (int c = 0; c < 19; c++) {
    i.GoNext();
  }
  ASSERT_EQ(i.GoNext(), false);
}

TEST(Text, save_in_file) {
  Text t("Prishli studenti.");
  ofstream fout("ForTest.txt");
  fout << t;
  fout.close();
  ifstream fin("ForTest.txt");
  string s;
  getline(fin, s);
  bool ok = true;
  TextIter i = t.GetRoot();
  int j = 0;
  while (i.GoNextChar()) {
    if (i.Get()->getC() != s[j]) {
      ok = false;
      break;
    }
    j++;
  }
  ASSERT_EQ(ok, true);
}

TEST(Text, text_copy_0) {
  Text t("Prishli studenti.");
  string s("Prishli studenti.");
  int cnt = 5;
  TextIter it = t.GetRoot();
  char* str = t.Copy(cnt, it);
  bool ok = true;
  for (int i = 0; i < cnt; i++) {
    if (str[i] != s[i]) {
      ok = false;
      break;
    }
  }
  ASSERT_EQ(ok, true);
}

TEST(Text, text_copy_1) {
  Text t("Prishli studenti.");
  string s("Prishli studenti.");
  int cnt = 15;
  TextIter it = t.GetRoot();
  char* str = t.Copy(cnt, it);
  bool ok = true;
  for (int i = 0; i < cnt; i++) {
    if (str[i] != s[i]) {
      ok = false;
      break;
    }
  }
  ASSERT_EQ(ok, true);
}

TEST(Text, text_copy_2) {
  Text t("Prishli studenti.");
  string s("Prishli studenti.");
  int cnt = s.size();
  TextIter it = t.GetRoot();
  char* str = t.Copy(cnt, it);
  bool ok = true;
  for (int i = 0; i < cnt; i++) {
    if (str[i] != s[i]) {
      ok = false;
      break;
    }
  }
  ASSERT_EQ(ok, true);
}

TEST(Text, text_find_0) {
  Text t("Prishli studenti.");
  TextIter it = t.Find('s');
  it.GoNextChar();
  ASSERT_EQ(it.Get()->getC(), 'h');
}

TEST(Text, text_find_1) {
  Text t("Prishli studenti.");
  TextIter it = t.Find('t');
  it.GoNextChar();
  ASSERT_EQ(it.Get()->getC(), 'u');
}

TEST(Text, text_find_2) {
  Text t("Pr studenti.");
  TextIter it = t.Find('i');
  it.GoNextChar();
  ASSERT_EQ(it.Get()->getC(), '.');
}

TEST(Text, text_insert_0) {
  Text t("abc def");
  string s("asbc def");
  TextIter it = t.GetRoot();
  it.GoNextChar();
  t.Insert("s", it);
  TextIter i = t.GetRoot();
  bool ok = true;
  for (int j = 0; j < s.size(); j++) {
    i.GoNextChar();
    if (i.Get()->getC() != s[j]) {
      ok = false;
      break;
    }
  }
  ASSERT_EQ(ok, true);
}

TEST(Text, text_insert_1) {
  Text t("abc def");
  string s("abc studenti def");
  TextIter it = t.GetRoot();
  it.GoNext();
  t.Insert("studenti ", it);
  TextIter i = t.GetRoot();
  bool ok = true;
  for (int j = 0; j < s.size(); j++) {
    i.GoNextChar();
    if (i.Get()->getC() != s[j]) {
      ok = false;
      break;
    }
  }
  ASSERT_EQ(ok, true);
}

TEST(Text, text_insert_2) {
  Text t("abc def ");
  string s("abc def studenti ");
  TextIter it = t.GetRoot();
  while (it.Get()->getC() !='f') {
    it.GoNextChar();
  };
  it.ResetToWord();
  t.Insert("studenti ", it);
  TextIter i = t.GetRoot();
  bool ok = true;
  for (int j = 0; j < s.size(); j++) {
    i.GoNextChar();
    if (i.Get()->getC() != s[j]) {
      ok = false;
      break;
    }
  }
  ASSERT_EQ(ok, true);
}

TEST(Text, text_find_word_0) {
  Text t("Prishli studenti na pary");
  TextIter it = t.FindWord("Prishli");
  it.GoNextChar();
  ASSERT_EQ(it.Get()->getC(), 'P');
}

TEST(Text, text_find_word_1) {
  Text t("Prishli studenti na pary");
  TextIter it = t.FindWord("pary");
  it.GoNextChar();
  it.GoNextChar();
  ASSERT_EQ(it.Get()->getC(), 'a');
}

TEST(Text, text_find_word_2) {
  Text t("Prishli Studenti na pary");
  TextIter it = t.FindWord("Studenti");
  it.GoNextChar();
  ASSERT_EQ(it.Get()->getC(), 'S');
}

TEST(Text, text_find_word_3) {
  Text t("Prishli Studenti na pary");
  TextIter it = t.FindWord("avdsadsa");
  ASSERT_EQ(it.IsEnd(), true);
}


TEST(Text, text_delete_0) {
  Text t("Prishli Studenti na pary");
  TextIter it = t.FindWord("Studenti");
  t.Delete(9, it);
  ofstream fout("ForTest.txt");
  fout << t;
  fout.close();
  ifstream fin("ForTest.txt");
  string s, sc("Prishli na pary");
  getline(fin, s);
  ASSERT_EQ(s == sc, true);
}

TEST(Text, text_delete_1) {
  Text t("Prishli Studenti na pary");
  TextIter it = t.Find('u');
  t.Delete(3, it);
  ofstream fout("ForTest.txt");
  fout << t;
  fout.close();
  ifstream fin("ForTest.txt");
  string s, sc("Prishli Stnti na pary");
  getline(fin, s);
  ASSERT_EQ(s == sc, true);
}

TEST(Text, text_delete_2) {
  Text t("Prishli Studenti na pary");
  TextIter it = t.Find('h');
  t.Delete(6, it);
  ofstream fout("ForTest.txt");
  fout << t;
  fout.close();
  ifstream fin("ForTest.txt");
  string s, sc("Prisudenti na pary");
  getline(fin, s);
  ASSERT_EQ(s == sc, true);
}

TEST(Text, text_delete_3) {
  Text t("Prishli Studenti na pary");
  TextIter it = t.FindWord("Studenti");
  t.Delete(13, it);
  ofstream fout("ForTest.txt");
  fout << t;
  fout.close();
  ifstream fin("ForTest.txt");
  string s, sc("Prishli ary");
  getline(fin, s);
  ASSERT_EQ(s == sc, true);
}

TEST(Text, text_delete_4) {
  Text t("Prishli Studenti na pary");
  TextIter it = t.FindWord("pary");
  t.Delete(4, it);
  ofstream fout("ForTest.txt");
  fout << t;
  fout.close();
  ifstream fin("ForTest.txt");
  string s, sc("Prishli Studenti na ");
  getline(fin, s);
  ASSERT_EQ(s == sc, true);
}