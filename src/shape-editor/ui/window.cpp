//
//bool EZGeoWindow::needInitialization=true ;
//bool EZGeoWindow::mouse_shape=false;
//bool EZGeoWindow::err=false;
//
//EZGeoWindow::EZGeoWindow( int w, int h, const char *name, EZGeoApp * _parent)
//        : EZWindow(w,h,name),parent(_parent)
//{
//    if(needInitialization)
//    {
//        needInitialization=false;
//        startTimer(1);
//    }
//    this->setDoubleBuffer(true);
//}
//
//void EZGeoWindow::close()
//{
//    delete this;
//}
//
///*
//     ###########################################################
//     ###############    Fonction Membre     ####################
//     ###########################################################
//*/
//
//
//void EZGeoWindow::expose()
//{
//    if(activeBackGroundImage)
//    {
//        auto width = getWidth();
//        auto height = getHeight();
//
//        try
//        {
//            EZImage bg_img("../ressources/LogoDoc_Autre_Bg.png");
//            bg_img.paint(*this,static_cast<int>( width - bg_img.getWidth() ) / 2,
//                         static_cast<int>( height - bg_img.getHeight()) / 2 );
//        }
//        catch( const std::runtime_error & )
//        {
//            std::cerr << "/!\\ Attention, l'image de fond (LogoDoc_Autre_Bg.png) n'est pas trouve dans le répertoire src/../ressources/LogoDoc_Autre_Bg.png /!\\" << std::endl;
//            activeBackGroundImage = false;
//        }
//    }
//
//    shapes.draw(*this);
//
//    interfaceShowUp();
//
//
//    if(mouse_shape)
//        drawText(EZAlign::TL, 3, 20, "Forme : "+saisie+"_");
//
//    if(err)
//        drawText(EZAlign::TL, 3, 20, str);
//}
//
//void EZGeoWindow::interfaceShowUp()
//{
//    int width = getWidth();
//    int height = getHeight();
//
//    this->setThick(2);
//
//    width >= 960 ? this->setFont(2) : this->setFont(1);
//
//    setColor(ez_white);
//    fillRectangle(0,0,width,24);
//    fillRectangle( 0, height - 24, width, height);
//
//    setColor(ez_black);
//
//    drawText(EZAlign::TC,width/2,5,"Mode : " + this->infoStr);
//    drawText(EZAlign::TL,5,5,"h pour afficher l'aide.");
//    drawText(EZAlign::TR,width-24,5,"Nombre d'objet actuel : " + std::to_string(this->shapes.getNumberShapes()) );
//
//    drawText( EZAlign::TR,width-128, height - 16, "Ctrl : ");
//    drawText( EZAlign::TR,width-24, height - 16, "Alt : ");
//
//    drawLine(0,24, width,24);
//    drawLine( 0, height - 24, width, height - 24);
//
//    setColor(ez_red);
//    if(!selector.getArray().empty())
//    {
//
//        fillRectangle( 8, height - 16, 16, height - 8);
//    }
//    if(holdLCtrl)
//    {
//        fillRectangle(width-128, height - 13, width - 114, height - 3);
//    }
//    if(holdLAlt)
//    {
//        fillRectangle(width-24, height - 13, width - 10, height - 3);
//    }
//
//    setColor(ez_black);
//
//    drawRectangle(width-128, height - 13, width - 114, height - 3);
//    drawRectangle(width-24, height - 13, width - 10, height - 3);
//    drawRectangle( 8, height - 16, 16, height - 8);
//
//    drawText( EZAlign::BL, 24, height - 6, "Nombre d'objet selectionnes : " + std::to_string( this->selector.getArray().size()));
//}
//
//
//void EZGeoWindow::buttonPress( int mouse_x, int mouse_y, int button)
//{
//    (this->*clickFunction)(mouse_x,mouse_y,button);
//    clickFunction = &EZGeoWindow::CLICK_selection;
//    infoStr = "Selection";
//    sendExpose();
//}
//
//void EZGeoWindow::motionNotify( int mouse_x, int mouse_y, int button)
//{
//    if( ( button == 1 || button == 3 && ppoint != nullptr) && !selector.getArray().empty() ) // Si on clique sur l'ancre d'une shape
//    {
//        if ( button == 1 && mouse_x >= 0 && mouse_y >= 0
//             && mouse_x < (int)this->getWidth() && mouse_y < (int)this->getHeight())
//        {
//            int baseX = selector.getArray()[0]->getXAnchor();
//            int baseY = selector.getArray()[0]->getYAnchor();
//
//            selector.getArray().at(0)->setSelected(true);
//            selector.getArray().at(0)->draw(*this);
//            selector.getArray().at(0)->moveShape(mouse_x,mouse_y); // on bouge les autres sommets
//
//
//            if(selector.getArray().size() > 1)
//                for ( std::size_t i = 1; i < selector.getArray().size(); i++)
//                {
//                    selector.getArray().at(i)->setSelected(true);
//                    selector.getArray().at(i)->draw(*this);
//
//                    selector.getArray().at(i)->setXYAnchor(selector.getArray().at(i)->getXAnchor() + mouse_x-baseX,
//                                                           selector.getArray().at(i)->getYAnchor() + mouse_y-baseY); // on bouge l'ancre.
//
//                    if(selector.getArray().at(i)->getNBSommets() > 0)
//                    {
//                        for ( std::size_t j = 0; j < selector.getArray().at( j)->getNBSommets(); j++)
//                            selector.getArray().at( j + 1)->setXYSommet( j,
//                                                                         selector.getArray().at( j + 1)->getXSommet( j) + mouse_x - baseX,
//                                                                         selector.getArray().at( j + 1)->getYSommet( j) + mouse_y - baseY);
//                    }
//                }
//
//        }
//
//            // Si on clique sur l'ancre de resize
//            // On redimensionne la forme
//        else {
//            selector.getArray().at(0)->setSelected(true);
//
//            selector.getArray().at(0)->draw(*this);
//
//            ppoint->setXY(mouse_x,mouse_y); // on bouge son point de resize
//
//            int loc_w = mouse_x-(selector.getArray().at(0)->getXAnchor());
//            int loc_h = mouse_y-(selector.getArray().at(0)->getYAnchor());
//
//            selector.getArray().at(0)->setSize(loc_w,loc_h, ppoint);
//        }
//
//        sendExpose();
//    }
//}
//
//// MAJ suzy, ajout du traitement de l'ancre de resize
//void EZGeoWindow::buttonRelease( int mouse_x, int mouse_y, int button)
//{
//    if(button == 1 && selector.getArray().size() >= 1) // Si on a cliqué sur l'anchor d'une shape
//    {
//        selector.getArray().at(0)->setSelected(true);
//    }
//
//    if(button == 3 && selector.getArray().size() == 1 && ppoint!=nullptr) // Si on clique sur l'ancre de resize avec le bouton droit de la souris
//    {
//        selector.getArray().at(0)->setSelected(false);
//
//        ppoint->setXY(mouse_x,mouse_y);
//
//        int loc_w = mouse_x-(selector.getArray().at(0)->getXAnchor());
//        int loc_h = mouse_y-(selector.getArray().at(0)->getYAnchor());
//
//
//        selector.getArray().at(0)->setSize(loc_w,loc_h, ppoint); // On redimensionne la forme
//        sendExpose();
//    }
//    else
//    {
//        sendExpose();
//    }
//
//
//    if(button == 2 && selector.getArray().size() >= 1 ) // Si on clique sur l'anchor  avec le bouton central de la souris
//    {
//        shapes.del(selector.getArray().at(0));
//        delete selector.getArray().at(0);
//        selector.clear();
//        sendExpose();
//    }
//
//
//}
//
//
//void EZGeoWindow::keyPress( EZKeySym keysym) // Une touche du clavier a ete enfoncée ou relachée
//{
//    // test Suzy
//    // Permet de saisir le nom d'une forme et de charger la forme adéquate
//    if (saisie_forme (keysym, saisie) == 1)
//    {
//        std::istringstream iss;
//        iss >> saisie;
//        std::ifstream f(saisie+".txt");
//        try
//        {
//            shapes.load(f);
//        }
//        catch(const std::exception& )
//        {
//            mouse_shape=false;
//            err=true;
//            str="Vous avez saisie une forme invalide";
//        }
//    }
//
//    if(!mouse_shape)
//    {
//        switch (keysym)
//        {
//            case EZKeySym::Escape:
//                selector.clear();
//                clickFunction = &EZGeoWindow::CLICK_selection;
//                infoStr = "Selection";
//                break;
//
//            case EZKeySym::Q:
//                EZDraw::quit();
//                std::cout << "Bruh";
//                break;
//
//            case EZKeySym::E:
//                std::cout << shapes;
//                break;
//
//            case EZKeySym::S: {
//                std::string tmp_str;
//                tmp_str = saisie_text(std::cin,"Veillez entrée une Nom de fichier de Sauvegarde : ");
//                try {
//                    std::ofstream f(tmp_str);
//                    shapes.save(f);
//                } catch(const std::exception & )
//                {
//                    std::cout << "Impossible sauvegarder" << std::endl;
//                }
//            }
//                break;
//
//            case EZKeySym::L: {
//                std::string tmp_str;
//                tmp_str = saisie_text(std::cin,"Entre un chemin de fichier de sauvegarde : ");
//                try {
//                    std::ifstream f(tmp_str);
//                    shapes.load(f);
//                } catch( const std::exception & )
//                {
//                    std::cout << "Impossible de lire le Fichier de sauvegarde" << std::endl;
//                }
//            }
//                break;
//
//            case EZKeySym::_0:
//                int r; int g; int b;
//                std::cout << "Veillez donner les RGB de votre couleur" << std::endl;
//                std::cout << "R : " << std::endl;
//                std::cin >> r;
//                std::cout << "G : " << std::endl;
//                std::cin >> g;
//                std::cout << "B : " << std::endl;
//                std::cin >> b;
//                setColorInSelector(getRGB(
//                        static_cast<EZuint8 >(r),
//                        static_cast<EZuint8 >(g),
//                        static_cast<EZuint8 >(b)
//                                         ));
//                break;
//
//
//            case EZKeySym::_1: setColorInSelector(ez_black);  break;
//            case EZKeySym::_2: setColorInSelector(ez_grey);  break;
//            case EZKeySym::_3: setColorInSelector(ez_red);  break;
//            case EZKeySym::_4: setColorInSelector(ez_green);  break;
//            case EZKeySym::_5: setColorInSelector(ez_blue);  break;
//            case EZKeySym::_6: setColorInSelector(ez_yellow);  break;
//            case EZKeySym::_7: setColorInSelector(ez_cyan);  break;
//            case EZKeySym::_8: setColorInSelector(ez_magenta);  break;
//            case EZKeySym::_9: setColorInSelector(ez_white);  break;
//            case EZKeySym::h:
//                std::cout << " -------------------- [ Aide ] -------------------- \n\n"
//                          << "[ Shift + Q ] : Quitter\n"
//                          << "[     h     ] : Cette aide\n"
//                          << "[  Escape   ] : Désélectionner toute les sélections\n"
//                          << "[ Shift + N ] : Créer une nouvelle fenêtre\n\n"
//                          << "------------------ [ Aide Souris ] ----------------- \n\n"
//                          << "[  Click 1  ] : Effectuer une action en fonction du mode\n"
//                          << "[  Click 2  ] : Supprimer la forme sélectionnée\n"
//                          << "[  Click 3  ] : Redimensionner la forme sélectionnée\n\n"
//                          << "------------------ [ Aide Forme ] -----------------\n\n"
//                          << "[ Shift + S ] : Sauvegarder des formes sur la fenêtre\n"
//                          << "[ Shift + L ] : Charger des formes sur la fenêtre\n"
//                          << "[ Shift + E ] : Écrire la liste des formes sur la console\n"
//                          << "[   Suppr   ] : Supprimer la forme sélectionnée\n"
//                          << "[     f     ] : Remplir une forme\n"
//                          << "[     r     ] : Passer en mode Création de Rectangle\n"
//                          << "[     e     ] : Passer en mode Création d'Ellipse\n"
//                          << "[     s     ] : Passer en mode Création de Carre\n"
//                          << "[     c     ] : Passer en mode Création de Cercle\n"
//                          << "[     t     ] : Passer en mode Création de Triangle\n"
//                          << "[     p     ] : Passer en mode Création de Polygone\n"
//                          << "[     g     ] : Passer en mode Création de Grille\n"
//                          << "[     z     ] : Passer en mode Création d'Etoile\n"
//                          << "[     a     ] : Passer en mode Création d'Image\n"
//                          << "[     m     ] : Passer en mode Création d'Image Animé\n"
//                          << "[     y     ] : Passer en mode Création de Text et d'édition de texte\n"
//                          << "[   Entree  ] : Passer en mode Création de Text avec une Font Image\n"
//                          << "[ Shift + F ] : Charger une nouvelle Font depuis un ficher de configuration\n\n"
//                          << "------------------ [ Aide Couleur ] -----------------\n\n"
//                          << "[     0     ] : Met la forme d'une couleur voulu\n"
//                          << "[     1     ] : Met en noire la forme\n"
//                          << "[     2     ] : Met en gris la forme\n"
//                          << "[     3     ] : Met en rouge la forme\n"
//                          << "[     4     ] : Met en vert la forme\n"
//                          << "[     5     ] : Met en bleu la forme\n"
//                          << "[     6     ] : Met en jaune la forme\n"
//                          << "[     7     ] : Met en cyan la forme\n"
//                          << "[     8     ] : Met en magenta la forme\n"
//                          << "[     9     ] : Met en blanc la forme\n\n"
//                          << "------------------ [ Aide Épaisseur ] ----------------- \n\n"
//                          << "[     +     ] : augmente l'épaisseur ou ajoute des lignes horizontales à une grille\n"
//                          << "[     -     ] : diminue l'épaisseur ou ajoute des lignes horizontales à une grille\n"
//                          << "[ + avec une selection ] : Augmente la taille d'une Image, Image Text ou Text\n"
//                          << "[ - avec une selection ] : Diminue la taille d'une Image, Image Text ou Text\n"
//                          << "------------------ [ Autre aide ] -----------------\n\n"
//                          << "[ Shift + W ] : Rotation vers la gauche d'une Image\n"
//                          << "[ Shift + C ] : Rotation vers la droite d'une Image\n"
//                          << "[ Shift + G ] : Cacher les lignes d'une Grille\n"
//                          << "[ Shift + P ] : Augmenter l'opacité d'une Image ou ajoute des lignes Verticales à une Grille\n"
//                          << "[ Shift + M ] : Diminuer l'opacité d'une Image ou ajoute des lignes Verticales à une Grille\n"
//                          << "[ Shift + T ] : Changer la taille de la grille pour l'appliquer sur toutes la fenêtre\n"
//                          << "[     b     ] : Activer l'image en arrière plan\n" << std::endl;
//
//                break;
//
//            case EZKeySym::b:
//                activeBackGroundImage = !activeBackGroundImage;
//                break;
//
//
//            case EZKeySym::r:
//                clickFunction = &EZGeoWindow::CLICK_makeRectangle;
//                infoStr = "Creation de Rectangle";
//
//                break;
//
//            case EZKeySym::m:
//                clickFunction = &EZGeoWindow::CLICK_makeAnimeImage;
//                infoStr = "Creation d'image animé";
//
//                break;
//
//            case EZKeySym::e:
//                clickFunction = &EZGeoWindow::CLICK_makeEllipse;
//                infoStr = "Creation de Ellipse";
//                break;
//
//            case EZKeySym::s:
//                clickFunction = &EZGeoWindow::CLICK_makeSquare;
//                infoStr = "Creation de Carre";
//                break;
//
//            case EZKeySym::c:
//                clickFunction = &EZGeoWindow::CLICK_makeCircle;
//                infoStr = "Creation de Cercle";
//                break;
//
//            case EZKeySym::t:
//
//                clickFunction = &EZGeoWindow::CLICK_makeTriangle;
//                infoStr = "Creation de Triangle";
//                break;
//
//            case EZKeySym::p:
//                clickFunction = &EZGeoWindow::CLICK_makePolygone;
//                infoStr = "Creation de Polygone";
//                break;
//
//            case EZKeySym::y:
//
//                if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Text)))
//                {
//                    Text * Element = dynamic_cast<Text *>(selector.getArray()[0]);
//                    Element->setText(saisie_text(std::cin,"Veillez saisire le nouveau texte : "));
//                }
//                else
//                {
//                    clickFunction = &EZGeoWindow::CLICK_makeText;
//                    infoStr = "Creation de Text";
//                }
//                break;
//
//            case EZKeySym::Return:
//                clickFunction = &EZGeoWindow::CLICK_makeImageFont;
//                infoStr = "Creation d'un Texte Image";
//                break;
//
//            case EZKeySym::F:
//                std::cout << "Veillez donne le nom du fichier de config (.txt) de la font : ";
//                std::cin >> actualFontImageFile;
//                break;
//
//            case EZKeySym::f:
//                if(!selector.getArray().empty())
//                    for (size_t i = 0; i < selector.getArray().size(); i++)
//                        selector.getArray().at(i)->changeFill();
//
//                break;
//
//            case EZKeySym::a:
//                clickFunction = &EZGeoWindow::CLICK_makeImage;
//                infoStr = "Creation d'une Image";
//                break;
//
//            case EZKeySym::w:
//                clickFunction = &EZGeoWindow::CLICK_makeText;
//                infoStr = "Creation d'un Text";
//                break;
//
//            case EZKeySym::z:
//                clickFunction = &EZGeoWindow::CLICK_makeStar;
//                infoStr = "Creation d'une Star";
//
//                break;
//
//            case EZKeySym::Control_L:
//                holdLCtrl = true;
//                break;
//
//            case EZKeySym::Alt_L:
//                holdLAlt = true;
//                break;
//
//            case EZKeySym::g:
//                clickFunction = &EZGeoWindow::CLICK_makeGrid;
//                break;
//
//            case EZKeySym::N:
//                parent->getArray().push_back(new EZGeoWindow( 720, 480, "Shape", parent));
//                break;
//
//            case EZKeySym::Delete:
//                for (size_t i = 0; i < selector.getArray().size(); i++)
//                {
//                    shapes.del(selector.getArray().at(i));
//                    selector.clear();
//                }
//                break;
//
//            case EZKeySym::minus:
//                if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Image)))
//                {
//                    Image * Element = dynamic_cast<Image *>(selector.getArray()[0]);
//                    if(Element->getZoom() > 1)
//                        Element->setZoom(Element->getZoom()-1);
//                }
//                else if(!selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(FontImage)))
//                {
//                    FontImage * Element = dynamic_cast<FontImage *>(selector.getArray()[0]);
//                    if(Element->getZoom() > 1)
//                        Element->setZoom(Element->getZoom()-1);
//                }
//                else if(!selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(AnimeImage)))
//                {
//                    AnimeImage * Element = dynamic_cast<AnimeImage *>(selector.getArray()[0]);
//                    if(Element->getZoom() > 1)
//                        Element->setZoom(Element->getZoom()-1);
//                }
//                else if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Grid)))
//                {
//                    Grid * Element = dynamic_cast<Grid *>(selector.getArray()[0]);
//                    Element->decreaseHLine();
//                }
//                else
//                    shapes.setThickAll(shapes.getShapeArray().at(0)->getThick()-1);
//
//                break;
//
//            case EZKeySym::plus:
//                if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Image)))
//                {
//                    Image * Element = dynamic_cast<Image *>(selector.getArray()[0]);
//                    Element->setZoom(Element->getZoom()+1);
//                }
//                else if(!selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(FontImage)))
//                {
//                    FontImage * Element = dynamic_cast<FontImage *>(selector.getArray()[0]);
//                    Element->setZoom(Element->getZoom()+1);
//                }
//                else if(!selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(AnimeImage)))
//                {
//                    AnimeImage * Element = dynamic_cast<AnimeImage *>(selector.getArray()[0]);
//                    Element->setZoom(Element->getZoom()+1);
//                }
//                else if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Grid)))
//                {
//                    Grid * Element = dynamic_cast<Grid *>(selector.getArray()[0]);
//                    Element->increaseHLine();
//                }
//                else
//                    shapes.setThickAll(shapes.getShapeArray().at(0)->getThick()+1);
//
//                break;
//
//            case EZKeySym::W:
//
//                if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Image)))
//                {
//                    Image * Element = dynamic_cast<Image *>(selector.getArray()[0]);
//                    Element->setRotation(Element->getRotation()+5);
//                }
//
//                break;
//
//            case EZKeySym::X:
//
//                if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Image)))
//                {
//                    Image * Element = dynamic_cast<Image *>(selector.getArray()[0]);
//                    Element->setRotation(Element->getRotation()-5);
//                }
//
//                break;
//
//            case EZKeySym::G:
//
//                if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Grid)))
//                {
//                    Grid * Element = dynamic_cast<Grid *>(selector.getArray()[0]);
//                    Element->invActivation();
//                }
//
//                break;
//
//            case EZKeySym::P:
//
//                if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Image)))
//                {
//                    Image * Element = dynamic_cast<Image *>(selector.getArray()[0]);
//                    if(Element->getOpacity() < 254)
//                        Element->setOpacity(Element->getOpacity()+1);
//                }
//                else if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Grid)))
//                {
//                    Grid * Element = dynamic_cast<Grid *>(selector.getArray()[0]);
//                    Element->increaseVLine();
//                }
//
//                break;
//
//            case EZKeySym::M:
//                if ( !selector.getArray().empty() ) {
//                    if ( typeid( *selector.getArray()[0] ) == typeid( Image ) )
//                    {
//                        Image *Element = dynamic_cast<Image *>(selector.getArray()[0]);
//                        if ( Element->getOpacity() > 0 )
//                            Element->setOpacity( Element->getOpacity() - 1 );
//                    }
//                    else if ( typeid( *selector.getArray()[0] ) == typeid( Grid ) ) {
//                        Grid *Element = dynamic_cast<Grid *>(selector.getArray()[0]);
//                        Element->decreaseVLine();
//                    }
//                }
//
//                break;
//
//            case EZKeySym::T:
//                if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Grid)))
//                {
//                    Grid * Element = dynamic_cast<Grid *>(selector.getArray()[0]);
//                    Element->setFeetToWindow(!Element->isFeetToWindow());
//                }
//                break;
//
//            case EZKeySym::O:
//
//                if( !selector.getArray().empty() && (typeid(*selector.getArray()[0]) == typeid(Image)))
//                {
//                    Image * Element = dynamic_cast<Image *>(selector.getArray()[0]);
//                    Element->setCanalAlpha(!Element->getCanalAlpha());
//                }
//                break;
//
//            default:
//                break;
//        }
//    }
//    sendExpose();
//}
//
//void EZGeoWindow::keyRelease( EZKeySym Key)
//{
//    switch (Key)
//    {
//        case EZKeySym::Control_L:
//            holdLCtrl = false;
//            break;
//
//        case EZKeySym::Alt_L:
//            holdLAlt = false;
//            break;
//
//        default:
//            break;
//    }
//
//    this->sendExpose();
//}
//
//int EZGeoWindow::saisie_forme( EZKeySym keysym, std::string& _saisie) const
//{
//    switch (keysym)
//    {
//        case EZKeySym::Return :
//            mouse_shape=false;
//            return 1;
//
//        case EZKeySym::Escape :
//            _saisie.erase( _saisie.begin(), _saisie.end());
//            sendExpose();
//            break;
//
//        case EZKeySym::BackSpace :
//            if ( _saisie.length() == 0 ) break;
//            _saisie.pop_back();
//            sendExpose();
//            break;
//
//        default :
//            if (currentEvent().keyCount() != 1) break;
//            _saisie.push_back( currentEvent().keyString()[0]);
//            sendExpose();
//            break;
//    }
//    return 0;
//}
//
//
//
//
///*
//     ###########################################################
//     ###############    Fonction Clique     ####################
//     ###########################################################
//*/
//
//void EZGeoWindow::CLICK_selection( int mouse_x, int mouse_y, int button)
//{
//    if(button == 1) /* Clique Gauche */
//    {
//        Shape* shape = shapes.isOver( mouse_x, mouse_y );
//        if ( shape != nullptr ) {
//            if ( selector.getArray().empty() ) {
//                selector.clear();
//                selector.add( shape );
//            }
//            else {
//                if ( !holdLCtrl ) {
//                    if ( selector.isSelected( shape ) && !selector.getArray().empty() ) {
//                        selector.setFirstPlace( shape );
//                    }
//                    else if ( !selector.getArray().empty() && shape != selector.getArray().at( 0 ) ) {
//                        selector.clear();
//                        selector.add( shape );
//                    }
//                }
//                else {
//                    if ( !selector.isSelected( shape ) && !selector.getArray().empty() ) {
//                        selector.add( shape );
//                        selector.setFirstPlace( shape );
//                    }
//                    else {
//                        if ( selector.isSelected( shape ) ) {
//                            selector.clear();
//                        }
//
//                        selector.add( shape );
//                    }
//                }
//            }
//        }
//    }
//
//    if(button == 3) //cliqueDroit
//    {
//        if(selector.getArray().size() >=2)
//            selector.clearExpecptfirst();
//
//        if(!selector.getArray().empty() && nullptr != selector.getArray().at(0)->isOverSommet(mouse_x,mouse_y))
//        {
//            if(this->ppoint != nullptr) {
//                ppoint = nullptr;
//            }
//
//            selector.clear();
//            selector.add(shapes.isResizing(mouse_x,mouse_y));
//
//            ppoint = selector.getArray().at(0)->isOverSommet(mouse_x,mouse_y);
//        }
//        else
//            selector.clear();
//    }
//}
//
//void EZGeoWindow::setColorInSelector( const EZColor newColor) const
//{
//    if(!selector.getArray().empty())
//        for ( auto & shape : selector.getArray() ) {
//            shape->setColor(newColor);
//        }
//}
//
//void EZGeoWindow::timerNotify()
//{
//    bool needRefresh = false;
//    for (size_t i = 0; i < shapes.getShapeArray().size(); i++)
//    {
//        if(typeid(*shapes.getShapeArray().at(i)) == typeid(AnimeImage))
//        {
//            AnimeImage * Element = dynamic_cast<AnimeImage *>(shapes.getShapeArray().at(i));
//            Element->nextFrame();
//            needRefresh = true;
//        }
//    }
//
//    if(needRefresh)
//        sendExpose();
//
//
//    startTimer(64);
//}
//
//void EZGeoWindow::CLICK_makeSquare( const int mouse_x, const int mouse_y, [[maybe_unused]] const int button )
//{
//    shapes.add(new Square(ez_black,1,mouse_x, mouse_y,32));
//}
//
//void EZGeoWindow::CLICK_makeRectangle( const int mouse_x, const int mouse_y, [[maybe_unused]] const int button )
//{
//    shapes.add(new Rectangle(ez_black,1,mouse_x,mouse_y,64,32));
//}
//
//void EZGeoWindow::CLICK_makeTriangle( const int mouse_x, const int mouse_y, [[maybe_unused]] const int button )
//{
//    shapes.add(new Triangle(ez_black,1,mouse_x,mouse_y,
//                            mouse_x+32,mouse_y-32,
//                            mouse_x-32,mouse_y-32));
//}
//
//void EZGeoWindow::CLICK_makeCircle( const int mouse_x, const int mouse_y, [[maybe_unused]] const int button )
//{
//    shapes.add(new Circle(ez_black,1,mouse_x,mouse_y,32));
//}
//
//void EZGeoWindow::CLICK_makeEllipse( const int mouse_x, const int mouse_y, [[maybe_unused]] const int button )
//{
//    shapes.add(new Ellipse(ez_black,1,mouse_x,mouse_y,32,64));
//}
//
//void EZGeoWindow::CLICK_makePolygone( const int mouse_x, const int mouse_y, [[maybe_unused]] const int button)
//{
//    if(!selector.getArray().empty())
//    {
//        selector.getArray().at(0)->addPoint(mouse_x,mouse_y);
//    }
//    else
//        shapes.add(new Polygone(ez_black,1,mouse_x,mouse_y,
//                                getWidth()/2,getHeight()/2-50,
//                                getWidth()/2-25,getHeight()/2-30,
//                                getWidth()/2+25,getHeight()/2-30,3));
//}
//
//void EZGeoWindow::CLICK_makeGrid( const int mouse_x, const int mouse_y, [[maybe_unused]] const int button )
//{
//    shapes.add(new Grid(mouse_x,mouse_y,8,8));
//}
//
//void EZGeoWindow::CLICK_makeImage( const int mouse_x, const int mouse_y, [[maybe_unused]] const int button)
//{
//    try
//    {
//        saisie = saisie_text(std::cin,"Veuillez renseigner un chemin : ");
//        shapes.add(new Image(mouse_x,mouse_y,saisie));
//    }
//    catch( const std::exception & )
//    {
//        std::cout << "Veillez Donner un chemin valide ..." << std::endl;
//    }
//    saisie = "";
//}
//
//void EZGeoWindow::CLICK_makeAnimeImage( const int mouse_x, const int mouse_y, [[maybe_unused]] const int button)
//{
//    try
//    {
//        int tmp_int;
//        saisie = saisie_text(std::cin,"Veuillez renseignez un chemin : ");
//
//        std::cout << "Veuillez donner le nombre de frames que votre image possède : ";
//        std::cin >> tmp_int;
//
//        shapes.add(new AnimeImage(mouse_x,mouse_y,saisie,tmp_int));
//    }
//    catch( const std::exception & )
//    {
//        std::cout << "Veillez Donner un chemin valide ..." << std::endl;
//    }
//
//    saisie = "";
//}
//
//void EZGeoWindow::CLICK_makeImageFont( const int mouse_x, const int mouse_y, [[maybe_unused]]int button)
//{
//    std::string tmpStr = saisie_text(std::cin,"Veuillez donner le texte à écrire : ");
//
//    for (char & letter : tmpStr)
//        letter = static_cast<char>( tolower(letter) );
//
//    try
//    {
//        shapes.add(new FontImage(tmpStr,"../ressources/Font/"+actualFontImageFile,
//                                 mouse_x, mouse_y));
//    }
//    catch(const std::exception& )
//    {
//        std::cerr << "Nom de fichier de font invalide ! (Lctrl + entree pour le changer)" << '\n';
//    }
//}
//
//void EZGeoWindow::CLICK_makeText( int mouse_x, int mouse_y, [[maybe_unused]]int button)
//{
//    shapes.add(new Text(saisie_text(std::cin,"Veillez donner le texte a ecrire : "),
//                        mouse_x,mouse_y,"Arial"));
//}
//
//void EZGeoWindow::CLICK_makeStar( int mouse_x, int mouse_y, [[maybe_unused]] int button)
//{
//    shapes.add(new Star(mouse_x,mouse_y,8,32,128));
//}
//
//EZGeoWindow::~EZGeoWindow() noexcept {
//    parent->getArray();
//}
