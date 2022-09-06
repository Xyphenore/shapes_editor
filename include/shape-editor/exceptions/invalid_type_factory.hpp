#ifndef INVALID_TYPE_FACTORY_HPP
#define INVALID_TYPE_FACTORY_HPP

#include <stdexcept>
#include <sstream>

class invalid_type_Factory
        : public std::invalid_argument {
private:
    std::string type;

    std::string msg_err{ "Type de forme inconnu \"" };

public:

    /// \warning Le constructeur par défaut est supprimé
    invalid_type_Factory() = delete;


    /// Construit une exception avec la std::string fournie
    /// \param[in] str_type : std::string. Le type de Shape non reconnue par la Factory
    /// \return invalid_type_Factory
    /// \warning Ne vérifie pas que la chaine fournie, contient le type de Shape voulant être construit
    /// \warning Ne vérifie pas que la chaine n'est pas vide
    explicit invalid_type_Factory( std::string str_type )
            : std::invalid_argument( nullptr ), type( std::move(
            str_type ) ) { msg_err += type += "\". Impossible de créer cette forme. Abandon de la création."; }


    /// Construit une exception avec la chaine C fournie
    /// \param[in] str_type : const char*. Le type de Shape non reconnue par la Factory
    /// \return invalid_type_Factory
    /// \warning Ne vérifie pas que la chaine fournie, contient le type de Shape voulant être construit
    /// \warning Ne vérifie pas que la chaine fournie, n'est pas vide
    /// \warning Ne vérifie pas que le pointeur fourni, soit différent de nullptr
    explicit invalid_type_Factory( const char* str_type )
            : invalid_type_Factory( std::string( str_type ) ) {}


    /// \warning Le constructeur de copie est supprimé
    invalid_type_Factory( const invalid_type_Factory& ) = delete;


    /// Construit une copie de l'exception fournie, en déplaçant son contenu vers celle créée
    /// \param[in] other : invalide_type_Factory&&. L'exception à affecter
    /// \warning Ne vérifie pas si l'exception fournie est bien construite ni si elle est valide
    invalid_type_Factory( invalid_type_Factory&& ) = default;


    /// Détruit une exception Invalid_TypeFactory
    ~invalid_type_Factory() override = default;

    /// Permet d'affecter par déplacement, une exception de type invalid_type_Factory, à l'exception courante de même type
    /// \param[in] other : invalide_type_Factory&&. L'exception à affecter
    /// \warning Ne vérifie pas si l'exception fournie est bien construite ni si elle est valide
    inline invalid_type_Factory& operator=( const invalid_type_Factory& other ) noexcept = default;


    /// Retourne le message d'erreur sous forme de chaine C
    /// \return const char*
    [[nodiscard]] inline const char* what() const noexcept override { return msg_err.c_str(); }
};


#endif //INVALID_TYPE_FACTORY_HPP
