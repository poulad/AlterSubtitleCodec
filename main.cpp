#include <QCoreApplication>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>

QString help()
{
   QString helpText =
         "AlterSubtitleCodec v0.0.1alpha  -  Written by Pouladpld<https://github.com/pouladpld>\n"
         "Alters subtitle codec to UTF-8. This Program is a free software. Licensed under GNU GPL v 3.0.\n\n"
         "Usage:\tAlterSubtitleCodec input [codec] output\n"
         "\t - Codecs: "
         "windows-1256\t\tPersian(Farsi), Arabic\n"
         "\t           cp1256\t\tPersian, Arabic\n"
         "\t More codecs are available at: https://www.iana.org/assignments/character-sets/character-sets.xhtml\n";
   return helpText;
}

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   QStringList arguments = a.arguments();
   qDebug() << arguments << '\n' << '\n';

   if(arguments.size() != 4 && !(arguments.size() == 2 && arguments.at(1) == "help" ) )
   {
      std::cout << help().toStdString();
      std::cout << "Error: arguments mismatch.";
      a.exit(-1);
   }

   if(arguments.size() == 2 && arguments.at(1) == "help")
   {
      std::cout << help().toStdString();
      a.exit(0);
      qApp->exit();
      qApp->quit();
   }
   else if (arguments.at(1) != "help")
   {
      std::cout << help().toStdString();
      std::cout << "Error: arguments mismatch.";
      a.exit(-1);
   }

   QFile input(arguments.at(1));
   if( !input.exists() || !input.open(QIODevice::ReadOnly))
   {
      qDebug() << "Error: input file doesn't exist or can not be opened.\nInput File: " + input.fileName();
      a.exit(1);
   }

   QFile output(arguments.last());
   if ( !output.open(QIODevice::WriteOnly) )
   {
      qDebug() << "Error: output file couldn't be opened for writing.Output File: " + output.fileName();
      a.exit(2);
   }

   QTextStream in(&input);
   QTextStream out(&output);

   char codec[25];
   for(int i = 0; i < arguments.at(2).size(); i++)
   {
      codec[i] = arguments.at(2).at(i).toLatin1();
   }
   char * inputCodec = &codec[0];

   in.setCodec(inputCodec);
   QString inputLine = "";

   while( !input.atEnd() )
   {
      inputLine = in.readLine();
      out << inputLine.toUtf8() << endl;
   }
   qApp->exit(0);
   a.exit(0);

   return a.exec();
}
