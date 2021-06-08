<div dir="rtl" lang="he">

# עץ בינארי עם איטרטורים

בקורס קודם למדתם (או הייתם אמורים ללמוד) על עצים בינאריים, ועל שלושת הדרכים לסייר בהם:
preorder, inorder, postorder.
במטלה הזאת המטרה היא לממש עץ בינארי עם איטרטורים שיכולים לעבור עליו בכל שלושת הסדרים.

שם המחלקה: `BinaryTree`.
השיטות הדרושות (ראו בקובץ [Demo.cpp](Demo.cpp) לפרטים):

* `add_root` - מקבלת קלט אחד ושמה אותו בשורש של העץ. אם כבר יש משהו בשורש, הוא מוחלף.
* `add_left` - מקבלת שני קלטים: הקלט הראשון מציין דבר שכבר קיים בעץ. הקלט השני מציין דבר חדש שיש להוסיף בתור הילד השמאלי שלו (אם כבר יש לו ילד שמאלי - יש להחליף את התוכן שלו). 
* `add_right` - כנ"ל, רק שהתוספת היא בתור הילד הימני.
* `begin_preorder()`, `end_preorder()` - מחזירות איטרטורים לצורך מעבר בסדר preorder (אב - שמאל - ימין).
* `begin_inorder()`, `end_inorder()` - מחזירות איטרטורים לצורך מעבר בסדר inorder (שמאל - אב - ימין).
* `begin_postorder()`, `end_postorder()` - מחזירות איטרטורים לצורך מעבר בסדר postorder (שמאל - ימין - אב).
* אופרטור פלט - מדפיס את העץ בפורמט הגיוני כלשהו לבחירתכם.

תוספות לחלק ב:
* **יעילות**: האיטרטור צריך להיות יעיל ככל האפשר מבחינת זיכרון. בפרט, אין לשמור את כל תוכן העץ בגוף האיטרטור. נסו למצוא פתרון יעיל יותר.
* כתבו בנאי מעתיק ואופרטור השמה המבצעים **העתקה עמוקה**, כמו שלמדנו בשיעור 5.
* כתבו בנאי מעביר ואופרטור העברה המבצעים **העתקה שטחית**, כמו שלמדנו בשיעור על פוינטרים חכמים.
* הפקודות `make test1`, `make test2`, `make test3`, `make tidy`, `make valgrind` צריכות לעבוד ללא שגיאות.
* כתבו תוכנית ראשית יצירתית לצורך הדגמה; לצורך התוכנית, השתמשו באלגוריתמים לבחירתכם מהספריה התקנית.


אין לשנות את הקבצים הנתונים, אלא רק להוסיף קבצים חדשים.

יש לפתור את המטלה באופן עצמאי.

* מותר להתייעץ עם סטודנטים אחרים או לחפש מידע באינטרנט;
אסור להעתיק קטעי-קוד שלמים מסטודנטים אחרים או מהאינטרנט.
* יש לדווח על כל עזרה שקיבלתם, מסטודנטים אחרים או מהאינטרנט, בהתאם ל[תקנון היושר של המחלקה](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).

</div>
# CPP_Ex5_BinaryTree_b
